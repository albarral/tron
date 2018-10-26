#ifndef __TRON_AI_EXPLORATION_H
#define __TRON_AI_EXPLORATION_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <log4cxx/logger.h>

#include "tron/ai/Explorer.h"
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
        Diagram* pDiagram;  // diagram to explore
        int start;                  // start state
        int target;                // target state
        std::vector<Explorer> listExplorers;      // list of explorers
        bool bfinished;         // exploration finished
        int numBlocked;         // number of explorers blocked
        int numArrived;         // number of explorers that reached the target
        
public:
    Exploration();
    ~Exploration();
    
    // initializes exploration data
    bool init(Diagram& oDiagram, int startState, int targetState);    
    // makes the explorer walk to a new state (returns true if it walked)
    bool run();    
    // computes shortest path to target
    Path getShortestPath();         
    
private:
    // make given explorer advance
    bool pushExplorer(Explorer& oExplorer);
    // create new explorers to explore the transitions ignored by the given explorer
    void createNewExplorers(Explorer& oExplorer);
};
}
#endif
