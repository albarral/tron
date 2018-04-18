#ifndef __TRON_CONTROL_CONTROLT_H
#define __TRON_CONTROL_CONTROLT_H

/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>
#include "tron/control/brooks/control.h"

namespace tron 
{
// This class implements a Brooks control connector for transmission of generic commands.
// It extends from base Control class.
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
