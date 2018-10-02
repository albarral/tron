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
    set2Normal();
    // default values
    setValues(1.0, 5.0, 25.0);    
    //default changes
    setChanges(1.0, 2.0);  
}

void ControlMagnitude::setLow(float value) 
{
    low = value;
    // update magnitude value after preset changed
    setMode(mode);
}

void ControlMagnitude::setNormal(float value) 
{
    normal = value;
    // update magnitude value after preset changed
    setMode(mode);
}

void ControlMagnitude::setHigh(float value) 
{
    high = value;
    // update magnitude value after preset changed
    setMode(mode);
}

void ControlMagnitude::setValues(float low, float normal, float high)
{
    this->low = low;
    this->normal = normal;  
    this->high = high;
    // update magnitude value after presets changed
    setMode(mode);
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

void ControlMagnitude::setMode(int mode)
{
    // check if low, normal or high mode
    if (mode >= 0 && mode < ControlMagnitude::eMAG_MANUAL)
    {
        this->mode = mode;
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
}

void ControlMagnitude::set2Low()
{
    setMode(ControlMagnitude::eMAG_LOW);
}

void ControlMagnitude::set2Normal()
{
    setMode(ControlMagnitude::eMAG_NORMAL);
}

void ControlMagnitude::set2High()
{
    setMode(ControlMagnitude::eMAG_HIGH);
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
