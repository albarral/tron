/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/sensor2.h"

namespace tron 
{
// Constructor
Sensor2::Sensor2()
{
    value = 0;
}
//Sensor2::~Sensor2();

void Sensor2::setValue(int val) 
{
    std::lock_guard<std::mutex> locker(mutex);
    value = val;
}

int Sensor2::getValue()
{
    std::lock_guard<std::mutex> locker(mutex);
    return value;
}
}


