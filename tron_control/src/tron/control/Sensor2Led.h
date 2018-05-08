#ifndef __TRON_CONTROL_SENSOR2LED_H
#define __TRON_CONTROL_SENSOR2LED_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/sensor2.h"

namespace tron
{
// This class represents a sensor led. 
// A device connected to a brooks sensor, that signals changes in the sensor value.
// The led turns ON on value change, and turns OFF on stable value.
// On init() the connection to the sensor is established. On check(), the sensor value is checked.
class Sensor2Led
{
private:
    Sensor2* pSensor;    // connection to monitored sensor 
    bool bconnected;      // connection established flag
    int last;           // last sensed value
    bool bON;       // led output (true when value changed since last check)

public:
    Sensor2Led();
    //~Sensor2Led();
        
    // set connection to sensor
    void init(Sensor2& oSensor);
    
    // reads sensor value and checks if it has changed
    bool check();
    
    bool isON() {return bON;};
};

}  

#endif
