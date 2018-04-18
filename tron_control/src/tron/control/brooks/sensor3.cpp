/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/sensor3.h"

namespace tron 
{
// Constructor
Sensor3::Sensor3()
{
    value = 0.0;
}
//Sensor3::~Sensor3();

void Sensor3::setValue(float val) 
{
    std::lock_guard<std::mutex> locker(mutex);
    value = val;
}

float Sensor3::getValue()
{
    std::lock_guard<std::mutex> locker(mutex);
    return value;
}
}


