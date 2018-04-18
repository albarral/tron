/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/sensor.h"

namespace tron 
{
// Constructor
Sensor::Sensor()
{
    value = false;
}
//Sensor::~Sensor();

void Sensor::setValue(bool val) 
{
    std::lock_guard<std::mutex> locker(mutex);
    value = val;
}

bool Sensor::getValue()
{
    std::lock_guard<std::mutex> locker(mutex);
    return value;
}
}


