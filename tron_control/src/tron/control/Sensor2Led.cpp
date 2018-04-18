/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/Sensor2Led.h"

namespace tron
{
SensorLed::SensorLed()
{          
    pSensor = 0;
    bconnected = false;
    bON = false;
    last = 0;
}

//SensorLed::~SensorLed ()
//{
//}

void SensorLed::init(Sensor2& oSensor)
{
    pSensor = &oSensor;
    bconnected = true;    
}

bool SensorLed::check()
{	
    // safety check 
    if (bconnected)
    {
        // read sensor
        int value = pSensor->getValue();
        // if value changed, led on
        if (value != last)
        {
            bON = true;
            last = pSensor->getValue();
        }
        // otherwise led off (if it was on)
        else if (bON)
            bON = false;        
    }

    return bON;
}
}




