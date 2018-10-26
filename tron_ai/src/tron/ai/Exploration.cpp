/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/ai/Exploration.h"
#include "tron/diagram/Transition.h"
#include "tron/diagram/TransitionPk.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Exploration::logger(Logger::getLogger("tron.ai"));
    
Exploration::Exploration() 
{
    start = target = -1;
    bfinished = false;
}

Exploration::~Exploration()
{
    listExplorers.clear();
}

bool Exploration::init(Diagram& oDiagram, int startState, int targetState)
{
    // create initial explorer 
    listExplorers.clear();
    Explorer oExplorer;
    // if initialized ok
    if (oExplorer.init(oDiagram, start, target))
    {
        // set start & target positions
        start = startState;
        target = targetState;
        // and add it to squad
        listExplorers.push_back(oExplorer);

        LOG4CXX_INFO(logger, "Exploration: initialized with start state = " << start << " and target = " << target);        
        LOG4CXX_INFO(logger, "Exploration: init ok");                
        return true;
    }
    else
    {
        LOG4CXX_WARN(logger, "Exploration: init failed!");                
        return false;
    }
}

bool Exploration::run()
{
    bfinished = false;
    numBlocked = 0;
    numArrived = 0;
    
    int numActive = listExplorers.size();
    while (numActive > 0)
    {
        numActive = 0;
        // make all active explorers walk
        for (Explorer& oExplorer : listExplorers)
        {
            if (oExplorer.isActive())
            {
                numActive++;
                pushExplorer(oExplorer);
            }
        }
    }
    
    return (numArrived > 0);
}

bool Exploration::pushExplorer(Explorer& oExplorer)
{
    // if explorer can advance
    if (oExplorer.advance())
    {
        // if explorer has ignored transitions
        if (oExplorer.hasIgnoredTransitions())
        {
            // create new explorers to explore them            
            createNewExplorers(oExplorer);
            // and clear them as they're not ignored anymore
            oExplorer.clearIgnoredTransitions();            
        }
    }
    // otherwise
    else
    {
        // check explorer blocked
        if (oExplorer.isBlocked())
            numBlocked++;
        // check explorer arrived
        else if (oExplorer.isArrived())
            numArrived++;                
    }
}

void Exploration::createNewExplorers(Explorer& oExplorer)
{
    // TO DO ...
}
}