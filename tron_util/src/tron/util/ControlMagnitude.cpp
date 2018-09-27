/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/ControlMagnitude.h"

namespace tron
{
ControlMagnitude::ControlMagnitude()
{
    // normal default mode
    setNormal();
    // default values
    setValues (1.0, 5.0, 25.0);    
    //default changes
    setChanges(1.0, 2.0);  
}

void ControlMagnitude::setValues(float lowValue, float normalValue, float highValue)
{
    low = lowValue;
    normal = normalValue;  
    high = highValue;
    
    // also update value depending on the mode (skip it if manual mode)
    switch (mode)
    {
        case ControlMagnitude::eMAG_LOW:
            value = low;
            break;
        case ControlMagnitude::eMAG_NORMAL:
            value = normal;
            break;
        case ControlMagnitude::eMAG_HIGH:
            value = high;
            break;
    }
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

void ControlMagnitude::setLow()
{
    value = low;
    mode = ControlMagnitude::eMAG_LOW;
}

void ControlMagnitude::setNormal()
{
    value = normal;
    mode = ControlMagnitude::eMAG_NORMAL;
}

void ControlMagnitude::setHigh()
{
    value = high;
    mode = ControlMagnitude::eMAG_HIGH;
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
