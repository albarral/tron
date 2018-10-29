#ifndef __TRON_AI_EXPLORATION_H
#define __TRON_AI_EXPLORATION_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <log4cxx/logger.h>

#include "tron/ai/Squad.h"
#include "tron/diagram/Diagram.h"
#include "tron/diagram/Path.h"

namespace tron
{
// Utility class used for exploring paths in state diagrams.
// It uses a dynamic squad of explorers, each following a different path to the target.    
class Exploration
{
private:    
        static log4cxx::LoggerPtr logger;
        
public:
    Exploration();
    ~Exploration();
    
    // initializes exploration data
    static std::vector<Path> explore(Diagram& oDiagram, int startState, int targetState);    
        
private:
    // makes the squad walk to new states (return true if it some explorer walked)
    static bool advanceSquad(Diagram& oDiagram, Squad& oSquad, int targetState);
    
    // create new explorers for given path to explore the specified transitions
    static void createNewExplorers(Diagram& oDiagram, Squad& oSquad, int targetState, Path& oPath, std::vector<TransitionPk>& listIgnoredTransitions);

    // create new explorer with the given path and push it through the specified transition
//    bool launchExplorer(Path& oPath, TransitionPk& oTransitionPk);
};
}
#endif
