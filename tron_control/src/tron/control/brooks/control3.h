#ifndef __TRON_CONTROL_CONTROL3_H
#define __TRON_CONTROL_CONTROL3_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>
#include "tron/control/brooks/control.h"

namespace tron 
{
// This class implements a Brooks control connector for transmission of float commands.
// It extends from base Control class.
// Thread safety implemented.
class Control3 : public Control
{
    private:
        float value;
        std::mutex mutex2;

    public:
        Control3();
        //~Control3();
        
        // Requests the execution of the control command with an input parameter and a given priority
        // returns true if the request is accepted
        bool request (float val, int vpriority = 0);
                        
        // just gets the last requested value
        float getValue();
};
}    
#endif
