#ifndef __TRON_CONTROL_MODULE4_H
#define __TRON_CONTROL_MODULE4_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>
#include <thread>

#include "tron/control/Behaviour.h"

namespace tron
{
// Class designed to run a behaviour inside its own thread.
// Methods to start & stop the module:
// - on() -> starts the module.
// - off()  -> asks the module to stop.
// - wait() -> waits till the thread is finished.
// Thread safety implemented.    
class Module4 
{
private:
        std::mutex mutex;
        std::thread t;        // module's thread       
        float frequency;    // required execution frequency
        int period;           // time (microseconds) to be slept between loop executions (inverse of the frequency)
        bool bON;            // flag indicating module running
        bool boffRequested;    // flag indicating thread stop was requested
        Behaviour* pBehaviour;  // implemented behaviour

public:
        Module4();
        Module4(Behaviour& oBehaviour);
        //~Module4();
                        
        // gets the loop frequency 
        float getFrequency();
        // gets the loop period (microsecs)
        int getPeriod();
        // checks if module is on
        bool isOn();
        // checks if off was requested
        bool isOffRequested();     
        // get assigned behaviour
        Behaviour* getBehaviour() {return pBehaviour;};

        // set the desired loop frequency (Hz)
        void setFrequency(float cps);
        // set behaviour to execute
        void setBehaviour(Behaviour& oBehaviour);
        // starts the thread
        void on();                
        // asks the thread to stop
        void off();        
        // waits for thread to end (after off requested)
        void wait();
        
private:
        // method running inside the thread 
        void run();        
};
}    
#endif
