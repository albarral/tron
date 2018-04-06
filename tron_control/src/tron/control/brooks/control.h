#ifndef __TRON_CONTROL_CONTROL_H
#define __TRON_CONTROL_CONTROL_H

/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>

namespace tron 
{
// This class implements a basic control command inside a control architecture.
// A flag is raised whenever the command is requested, and it is lowered down whenever the command state is checked. 
// It allows for suppression mechanism (Brooks subsumption architecture) by allowing requests with different priorities, always executing the request of highest priority.
// Thread safety implemented.
class Control 
{
    protected:
        std::mutex mutex1;
        bool brequested;           // command requested flag        
        int priority;                    // active priority (highest of received requests)

    public:
        Control();
        //~Control();
                        
        // Requests the execution of the control command with a given priority
        // returns true if the request is accepted
        bool request(int vpriority = 0);

        // Checks if a command request is pending to be executed.
        // After the check, the request is considered not pending anymore.
        bool checkRequested();        
        
        bool getRequested() {return brequested;};
        int getPriority() {return priority;};
};
}    
#endif
