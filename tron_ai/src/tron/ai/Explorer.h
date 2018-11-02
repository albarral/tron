#ifndef __TRON_AI_EXPLORER_H
#define __TRON_AI_EXPLORER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "tron/diagram/Diagram.h"
#include "tron/diagram/TransitionPk.h"
#include "tron/diagram/Walker.h"

namespace tron
{
// Utility class for exploring paths in state diagrams.
// Two exploration modes available: free and oriented.    
// Free mode - the explorer walks any of the available transitions: 
// if 0 transitions: explorer is blocked
// if 1 transition: it walks this one
// if +1 transitions: it walks a selected one & ignores the rest adding them an ignored list
// Oriented mode - the explorer walks the specified transition:
// if 0 transitions: explorer is blocked
// if +0 transitions: it walks the specified one if it exists
// single usage: after an oriented walk, the exploration is set back to free mode automatically.
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
        int ID;                         // explorer ID
        int status;                 // explorer status (one of eStatus values)        
        int target;                // target state
        bool boriented;         // oriented mode (on true, the advance takes a specified transition)
        int transitionID;         // specified transition for oriented mode exploration
        std::vector<TransitionPk> listIgnoredTransitions;      // list of ignored transitions
        
public:
    Explorer();
    ~Explorer();
    
    int getID() {return ID;};
    int getSatus() {return status;};
    int getTarget() {return target;};
    int getOrientedTransition() {return transitionID;};
    std::vector<TransitionPk>& getIgnoredTransitions() {return listIgnoredTransitions;};     
    
    void setID(int id) {ID = id;};
    // initialize explorer data
    bool init(Diagram& oDiagram, int startState, int targetState);    
    // orient explorer to given transition
    void orient(int transitionID);
    // make explorer walk either in free or oriented mode (returns true if it walked)
    bool advance();
    // check if there are ignored transitions
    bool hasIgnoredTransitions() {return !listIgnoredTransitions.empty();};
    // clear the list of ignored transitions
    void clearIgnoredTransitions();         
    
    bool isActive() {return status == eSTATUS_ACTIVE;};
    bool isArrived() {return status == eSTATUS_ARRIVED;};
    bool isBlocked() {return status == eSTATUS_BLOCKED;};    
    
    // get short description of the explorer
    std::string shortDesc();
    // get status description
    static std::string statusDesc(int status);

private:
    // update status depending on walk result and if target reached 
    void updateStatus(bool bwalked);
};
}
#endif
