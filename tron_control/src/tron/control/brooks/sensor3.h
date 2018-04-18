#ifndef __TRON_CONTROL_SENSOR3_H
#define __TRON_CONTROL_SENSOR3_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>

namespace tron 
{
// This class implements a Brooks sensor for transmission of boolean info.
// Thread safety implemented.
class Sensor3 
{
    private:
        std::mutex mutex;
        float value; 

    public:
        Sensor3();
        //~Sensor3();
                        
        // Sets the sensor info
        void setValue(float val);         
        // Gets the sensor info
        float getValue();
};
}    
#endif
