/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/ai/Exploration.h"
#include "tron/ai/Explorer.h"
//#include "tron/diagram/Transition.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Exploration::logger(Logger::getLogger("tron.ai"));
    

std::vector<Path> Exploration::explore(Diagram& oDiagram, int startState, int targetState)
{
    LOG4CXX_INFO(logger, "Exploration.explore(): start = " << startState << ", target = " << targetState);        
    std::vector<Path> listPaths;
                
    // create squad with initial explorer 
    Squad oSquad;    
    Explorer oExplorer;
    // if explorer initialized add it to squad
    if (oExplorer.init(oDiagram, startState, targetState))
        oSquad.addExplorer(oExplorer);
    else
    {
        LOG4CXX_WARN(logger, "Exploration: failed!");                
        return listPaths;
    }
    
    // make the squad advance over the diagram
    bool bexplore = true;
    while (bexplore)
    {
        bexplore = advanceSquad(oDiagram, oSquad, targetState);
    }
    
    // if explorers arrived to target, get their paths    
    if (oSquad.getNumArrived() > 0)
    {
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
    std::list<Explorer>::iterator itExplorer = oSquad.getListExplorers().begin();
      
    int numWalks = 0;
    while (itExplorer != oSquad.getListExplorers().end())
    {
        if (itExplorer->isActive())
        {
            if (itExplorer->advance())
            {
                numWalks++;
                
                // if explorer left transitions ignored
                if (itExplorer->hasIgnoredTransitions())
                { 
                    // get path copy without last transition
                    Path oPath2 = itExplorer->getPath();
                    oPath2.popLast();
                
                    // create new explorers to explore them            
                    createNewExplorers(oDiagram, oSquad, targetState, oPath2, itExplorer->getIgnoredTransitions());
                    
                    // and clear them (as they're not ignored anymore)
                    itExplorer->clearIgnoredTransitions();            
                }
            }
                            
            itExplorer++;                
        }
        //  remove blocked explorers from squad
        else if (itExplorer->isBlocked())
        {
            oSquad.removeExplorer(itExplorer);
        }
    }
    
    return (numWalks > 0);
}


void Exploration::createNewExplorers(Diagram& oDiagram, Squad& oSquad, int targetState, Path& oPath, std::vector<TransitionPk>& listTransitions)
{
    for (TransitionPk& transitionPk : listTransitions)
    {
        Explorer oExplorer;
        // if initialized ok
        if (oExplorer.init(oDiagram, oPath.getOrigin(), targetState))
        {
            oExplorer.setNewPath(oPath);
            oSquad.addExplorer(oExplorer);
        }        
    }        
}

}