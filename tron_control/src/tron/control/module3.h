#ifndef __TRON_CONTROL_MODULE3_H
#define __TRON_CONTROL_MODULE3_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>
#include <string>
#include <thread>

namespace tron
{
// Base class designed to run a module inside its own thread.
// The first() and loop() methods must be implemented in the derived class: .    
// Methods to start & stop the module:
// - on() -> starts the module.
// - off()  -> asks the module to stop.
// - wait() -> waits till the thread is finished.
// Thread safety implemented.    
class Module3 
{
private:
        std::mutex mutex;
        std::thread t;        // module's thread       
        bool bON;            // flag indicating module running
        int state;             // module's present state
        int prevState;       // module's previous state
        int stable;            // cycles without state changes (limited to 1000)            
        float frequency;    // required execution frequency
        int period;           // time (microseconds) to be slept between loop executions
        bool boffRequested;    // indicates off has been requested
        static const int state_UNKNOWN = 100;
        int level;              // module's level (hierarchy level in the control architecture)
protected:
        std::string modName;   // module name

public:
        Module3();
        //~Module3();
                
        std::string getModuleName() {return modName;};

        // starts the thread
        void on();                
        // asks the thread to stop
        void off();        
        // waits till the thread is finished
        void wait();
        // checks if module is on
        bool isOn();
        
        // sets the desired loop frequency 
        void setFrequency(float cps);
        // gets the loop frequency 
        float getFrequency();
        // gets the loop period (microsecs)
        int getPeriod();

        // checks the module state
        int getState();
        // checks the module previous state
        int getPrevState();
        
        void setLevel(int value) {level = value;};
        int getLevel() {return level;};
        
protected:
        // method running inside the thread 
        void run();
        // checks if off was requested
        bool offRequested();     
        
        // first actions when the thread begins 
        virtual void first() = 0;
        // loops inside the thread 
        virtual void loop() = 0;            
        
        // sets a new state (ignore it if in OFF state)
        void setState(int value);
        // checks if state has changed in last loop
        bool isStateChanged();
        // gets stable cycles in same state
        int getStable();        
        // gets stable time in milliseconds (limited due to limited stability counter)
        int getStableTime();        
        
private:        
        // prepare for new loop
        void preLoop();
        // check loop changes
        void postLoop();
};
}    
#endif
