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
    while (bexplore)
    {
        bexplore = advanceSquad(oDiagram, oSquad, targetState);
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

bool Exploration::advanceSquad(Diagram& oDiagram, Squad& oSquad, int targetState)
{          
    int numWalks = 0;

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
                numWalks++;
                
                // if explorer left transitions ignored
                if (itExplorer->hasIgnoredTransitions())
                { 
                    int startState = itExplorer->getPath().getOrigin();
                    // get path without last transition
                    Path oFromPath = itExplorer->getPath();
                    oFromPath.popLast();
                                    
                    // create new explorers to explore the ignored transitions
                    deployNewExplorers(oDiagram, oSquad, oFromPath, itExplorer->getIgnoredTransitions(), startState, targetState);
                    
                    // and clear them 
                    itExplorer->clearIgnoredTransitions();            
                }
            }                        
        }

        itExplorer++;                
        // if explorer is blocked, remove it from squad
//        else if (itExplorer->isBlocked())
//            oSquad.removeExplorer(itExplorer);
    }
    
    LOG4CXX_INFO(logger, "Exploration.advanceSquad(): num walks = " << numWalks);        
    
    // return number of advances
    return (numWalks > 0);
}


void Exploration::deployNewExplorers(Diagram& oDiagram, Squad& oSquad, Path& oPath, std::vector<TransitionPk>& listTransitions, int startState, int targetState)
{
    LOG4CXX_INFO(logger, "Exploration.deployNewExplorers(): deploying " << listTransitions.size() << " explorers");        
    
    // for each transition in the list
    for (TransitionPk& transitionPk : listTransitions)
    {
        // create a new explorer and make him walk the transition
        Explorer oExplorer;
        // initialize explorer 
        if (oExplorer.init(oDiagram, startState, targetState))
        {
            // set path (if not empty)
            if (!oPath.isEmpty())
                oExplorer.setNewPath(oPath);
            // make him walk
            oExplorer.advance(transitionPk.getTransitionID());
            // and add to squad
            oSquad.addExplorer(oExplorer);
        }        
    }        
}

}