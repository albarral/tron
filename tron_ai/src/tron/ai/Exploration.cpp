/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/ai/Exploration.h"
#include "tron/ai/Explorer.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Exploration::logger(Logger::getLogger("tron.ai"));
    

std::vector<Path> Exploration::explore(Diagram& oDiagram, int startState, int targetState)
{
    LOG4CXX_INFO(logger, "Exploration.explore(): start = " << startState << ", target = " << targetState);        
    std::vector<Path> listPaths;
                
    // create squad and initial explorer 
    Squad oSquad;    
    Explorer oExplorer;
    // initialize explorer and add it to squad
    if (oExplorer.init(oDiagram, startState, targetState))
        oSquad.addExplorer(oExplorer);
    else
    {
        LOG4CXX_WARN(logger, "Exploration: failed!");                
        return listPaths;
    }
    
    // make the squad advance iteratively
    bool bexplore = true;
    int iteration = 0;
    while (bexplore)
    {
        bexplore = advanceSquad(oDiagram, oSquad, targetState, ++iteration);
    }
    
    oSquad.checkNumbers();

    if (oSquad.getNumBlocked() > 0)
    {
        LOG4CXX_INFO(logger, "Exploration.explore(): explorers blocked = " << oSquad.getNumBlocked());        
    }

    // if any explorers arrived, return their paths    
    if (oSquad.getNumArrived() > 0)
    {
        LOG4CXX_INFO(logger, "Exploration.explore(): explorers arrived = " << oSquad.getNumArrived());        
        for (Explorer& oExplorer : oSquad.getListExplorers())
        {
            if (oExplorer.isArrived())
                listPaths.push_back(oExplorer.getPath());
        }
    }

    return listPaths;
}

bool Exploration::advanceSquad(Diagram& oDiagram, Squad& oSquad, int targetState, int iteration)
{          
    int numWalks = 0;

    LOG4CXX_INFO(logger, "Exploration: iteration ... " << iteration);        

    std::list<Explorer>::iterator itExplorer = oSquad.getListExplorers().begin();
    std::list<Explorer>::iterator itEnd = oSquad.getListExplorers().end();
    
    // walk the explorers squad
    while (itExplorer != itEnd)
    {
        // if explorer is active
        if (itExplorer->isActive())
        {
            // make it advance
            if (itExplorer->advance())
            {
                LOG4CXX_DEBUG(logger, "Exploration: " + itExplorer->shortDesc() + " ok");        
                numWalks++;
                
                // if explorer left transitions ignored
                if (itExplorer->hasIgnoredTransitions())
                { 
                    // create new explorers to explore the ignored transitions
                    deployNewExplorers(oDiagram, oSquad, targetState, itExplorer->getPath(), itExplorer->getIgnoredTransitions());                    
                    // and clear them 
                    itExplorer->clearIgnoredTransitions();            
                }
            }                       
            else
            {
                LOG4CXX_DEBUG(logger, "Exploration: " + itExplorer->shortDesc() + " failed, " + Explorer::statusDesc(itExplorer->getSatus()));        
            }
        }
        else
        {
            LOG4CXX_DEBUG(logger, "Exploration: " + itExplorer->shortDesc() + " " + Explorer::statusDesc(itExplorer->getSatus()));        
        }

        itExplorer++;                
        // if explorer is blocked, remove it from squad
//        else if (itExplorer->isBlocked())
//            oSquad.removeExplorer(itExplorer);
    }
        
    // return number of advances
    return (numWalks > 0);
}


void Exploration::deployNewExplorers(Diagram& oDiagram, Squad& oSquad, int targetState, Path& oPath, std::vector<TransitionPk>& listTransitions)
{    
    int startState = oPath.getOrigin();
    // the new explorers will be placed at the same common path (a step previous to the specified path), but oriented to different transitions
    Path oCommonPath = oPath;
    oCommonPath.popLast();
    
    // for each ignored transition
    for (TransitionPk& transitionPk : listTransitions)
    {
        // create new explorer 
        Explorer oExplorer;
        // initialize it
        if (oExplorer.init(oDiagram, startState, targetState))
        {
            // set its path (if not empty)
            if (!oCommonPath.isEmpty())
                oExplorer.setNewPath(oCommonPath);
            // and orient it towards the ignored transition
            oExplorer.orient(transitionPk.getTransitionID());
            // finally add it to squad
            oSquad.addExplorer(oExplorer);
            
            LOG4CXX_DEBUG(logger, "Exploration: new deploy -> " << oExplorer.shortDesc());                  
        }        
    }        
}

}