#ifndef __TULY_SENSOR_H
#define __TULY_SENSOR_H

/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>

namespace tuly 
{
// This class implements a Brooks sensor.
// Thread safety implemented.
class Sensor 
{
    protected:
        std::mutex mutex;
        bool bvalue; 

    public:
        Sensor()
        {
            bvalue = false;
        }
        //~Sensor();
                        
        // Sets the sensor info
        void setValue(bool value) 
        {
            std::lock_guard<std::mutex> locker(mutex);
            this->bvalue = value;
        };
        
        // Gets the sensor info
        bool getValue()
        {
            std::lock_guard<std::mutex> locker(mutex);
            return bvalue;
        };
};
}    
#endif
