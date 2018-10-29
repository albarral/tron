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
// Utility class for exploring paths in state diagrams.
// The exploration strategy depends on the number of transitions in the present state: 
// 0 transitions: explorer blocked
// 1 transition: explorer walks it
// +1 transitions: explorer walks one & ignores the rest (adds them to the ignored list)
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
        int target;                // target state
        std::vector<TransitionPk> listIgnoredTransitions;      // list of ignored transitions
        
public:
    Explorer();
    ~Explorer();
    
    int getSatus() {return status;};
    int getTarget() {return target;};
    std::vector<TransitionPk>& getIgnoredTransitions() {return listIgnoredTransitions;};     
    
    // initializes explorer data
    bool init(Diagram& oDiagram, int startState, int targetState);    
    // makes explorer walk through given transition (returns true if it walked)
    bool advance(int transitionID=0);
    // check if there are ignored transitions
    bool hasIgnoredTransitions() {return !listIgnoredTransitions.empty();};
    // clear the list of ignored transitions
    void clearIgnoredTransitions();         
    
    bool isActive() {return status == eSTATUS_ACTIVE;};
    bool isArrived() {return status == eSTATUS_ARRIVED;};
    bool isBlocked() {return status == eSTATUS_BLOCKED;};    
    
private:
    // walk through given transition and check if target reached (returns true if walked)
    bool walkAndCheck(int transitionID);
};
}
#endif
