#ifndef __TRON_CONTROL_SENSORLED_H
#define __TRON_CONTROL_SENSORLED_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/sensorT.h"

namespace tron
{
// This class represents a sensor led. 
// A device connected to a brooks sensor, that signals changes in the sensor value.
// The led turns ON on value change, and turns OFF on stable value.
// On init() the connection to the sensor is established. On check(), the sensor value is checked.
class SensorLed
{
private:
    SensorT<int>* pSensor;    // connection to monitored sensor 
    bool bconnected;      // connection established flag
    int last;           // last sensed value
    bool bON;       // led output (true when value changed since last check)

public:
    SensorLed();
    //~SensorLed();
        
    // set connection to sensor
    void init(SensorT<int>& oSensor);
    
    // reads sensor value and checks if it has changed
    bool check();
    
    bool isON() {return bON;};
};

}  

#endif
