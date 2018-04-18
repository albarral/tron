#ifndef __TRON_CONTROL_SENSOR2_H
#define __TRON_CONTROL_SENSOR2_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>

namespace tron 
{
// This class implements a Brooks sensor for transmission of integer info.
// Thread safety implemented.
class Sensor2 
{
    private:
        std::mutex mutex;
        int value; 

    public:
        Sensor2();
        //~Sensor2();
                        
        // Sets the sensor info
        void setValue(int val);         
        // Gets the sensor info
        int getValue();
};
}    
#endif
