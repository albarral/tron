#ifndef __TULY_CONTROLT_H
#define __TULY_CONTROLT_H

/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>
#include "tuly/control/brooks/control.h"

namespace tuly 
{
// This class implements a Brooks control command.
// It works as the base Control class, but allows for an input parameter on the command request.
// Thread safety implemented.
template <typename T>
class ControlT : public Control
{
    protected:
        T value;
        std::mutex mutex2;

    public:
        ControlT();
        //~ControlT();
        
        // Requests the execution of the control command with an input parameter and a given priority
        // returns true if the request is accepted
        bool request (T value, int vpriority = 0);
                        
        // just gets the last requested value
        T getValue();
};

// note: DEFINITIONS OF TEMPLATE CLASSES MUST BE PLACED IN HEADER

// Constructor
template <typename T>
ControlT<T>::ControlT()
{      
    value = 0;
}
    
template <typename T>
bool ControlT<T>::request(T value, int vpriority)
{  
    std::lock_guard<std::mutex> locker(mutex2);
    
    // if a new request can be made (due to winner priority), the control value is updated
    if (Control::request(vpriority))
    {
        this->value = value;    
        return true;
    }
    else 
        return false;          
}

template <typename T>
T ControlT<T>::getValue()
{
    std::lock_guard<std::mutex> locker(mutex2);
    
    return value;
}

}    
#endif
