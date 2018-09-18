/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/ControlMagnitude.h"

namespace tron
{
ControlMagnitude::ControlMagnitude()
{
    // default values
    setValues (1.0, 5.0, 25.0);    
    //default changes
    setChanges(1.0, 2.0);  
    // normal default mode
    setMode(ControlMagnitude::eMAG_NORMAL);
}

void ControlMagnitude::setValues(float lowValue, float normalValue, float highValue)
{
    low = lowValue;
    normal = normalValue;  
    high = highValue;
}

void ControlMagnitude::setChanges(float additiveChange, float proportionalChange)
{
    // additive change param must be positive
    if (additiveChange > 0.0)
        change = additiveChange;
    // proportional change param must be positive
    if (proportionalChange > 0.0)
        xchange = proportionalChange;
}

bool ControlMagnitude::setMode(int val)
{
    switch (val)
    {
        case ControlMagnitude::eMAG_LOW:
            value = low;
            mode = val;
            break;
            
        case ControlMagnitude::eMAG_NORMAL:
            value = normal;
            mode = val;
            break;

        case ControlMagnitude::eMAG_HIGH:
            value = high;
            mode = val;
            break;
            
        default:
            // if invalid mode, return false
            return false;
    }
    
    return true;
}

void ControlMagnitude::increase()
{
    value += change;
    if (mode != ControlMagnitude::eMAG_MANUAL)
        mode = ControlMagnitude::eMAG_MANUAL;    
}

void ControlMagnitude::decrease()
{
    value -= change;
    if (mode != ControlMagnitude::eMAG_MANUAL)
        mode = ControlMagnitude::eMAG_MANUAL;    
}

void ControlMagnitude::increaseX()
{
    value = value * xchange;
    if (mode != ControlMagnitude::eMAG_MANUAL)
        mode = ControlMagnitude::eMAG_MANUAL;    
}

void ControlMagnitude::decreaseX()
{
    // xchange can never be zero
    value = value / xchange;
    if (mode != ControlMagnitude::eMAG_MANUAL)
        mode = ControlMagnitude::eMAG_MANUAL;    
}
}
