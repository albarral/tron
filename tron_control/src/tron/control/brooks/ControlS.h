#ifndef __TRON_CONTROL_CONTROLS_H
#define __TRON_CONTROL_CONTROLS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>
#include <string>
#include "tron/control/brooks/control.h"

namespace tron 
{
// Brooks control connector for transmission of string commands.
// It extends from base Control class.
// Thread safety implemented.
class ControlS : public Control
{
    private:
        std::string value;
        std::mutex mutex2;

    public:
        ControlS();
        //~ControlS();
        
        // Requests the execution of the control command with an input parameter and a given priority
        // returns true if the request is accepted
        bool request (std::string val, int vpriority = 0);
                        
        // just gets the last requested value
        std::string getValue();
};
}    
#endif
