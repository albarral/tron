#ifndef __TRON_AI_EXPLORER_H
#define __TRON_AI_EXPLORER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>
#include <log4cxx/logger.h>

#include "tron/diagram/Diagram.h"
#include "tron/diagram/TransitionPk.h"
#include "tron/diagram/Walker.h"

namespace tron
{
// Utility class used for exploring paths in state diagrams.
// Exploration strategy depending on state transitions: 
// 0 transitions: explorer blocked
// 1 transition: explorer walks it
// +1 transitions: explorer walks one transition & adds the other ones to a list of pending transitions
// A father supervisor object creates new explorers to explore the pending transitions.    
class Explorer : public Walker
{
public:
    enum eStatus
    {
        eSTATUS_ACTIVE,                 // explorer walking freely
        eSTATUS_ARRIVED,                // explorer reached target state
        eSTATUS_BLOCKED              // explorer reached dead-end state
    };
    
private:
        static log4cxx::LoggerPtr logger;
        int status;                 // explorer status (one of eStatus values)        
        int start;                  // start state
        int target;                // target state
        std::vector<TransitionPk> listPendingTransitions;      // list of pending transitions
        
public:
    Explorer();
    ~Explorer();
    
    // get list of pending transitions
    std::vector<TransitionPk>& getPendingTransitions() {return listPendingTransitions;};     
    
    // initializes explorer data
    bool init(Diagram& oDiagram, int startState, int targetState);
    
    // makes the explorer advance to a new diagram state (returns false if blocked)
    bool go();
    
    // clear the list of pending transitions
    void clearPendingTransitions();         
    
private:
    // walk through given transition and check if target reached
    void walkAndCheck(int transition);
};
}
#endif
