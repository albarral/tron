#ifndef __AMY_MODULE2_H
#define __AMY_MODULE2_H

/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>
#include <string>
#include <thread>

namespace tron
{
// Base class designed to run a module inside its own thread.
// Method to be implemented in the derived class: loop().    
// Methods to start & stop the module:
// - on() -> starts the module.
// - off()  -> asks the module to stop.
// - wait() -> waits till the thread is finished.
// Thread safety implemented.    
class Module2 
{
private:
        std::mutex mutex;
        std::thread t;        // module's thread       
        int state;             // module's present state
        int nextState;       // module's next state
        float frequency;    // 
        int period;           // time (microseconds) to be slept between loop executions
        static const int state_OFF = 99;
        static const int state_ON = 100;
        static const int state_UNKNOWN = 101;

public:
        Module2();
        //~Module2();
    
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

        // checks the module state
        int getState();
        // gets the next state
        int getNextState();
                
protected:
        // method running inside the thread 
        void run();
        // checks if off was requested
        bool offRequested();     
        
        // first actions when the thread begins 
        virtual void first() = 0;
        // loops inside the thread 
        virtual void loop() = 0;            
        
        // sets the state directly (to be used only in special cases)
        void setState(int state);
        // sets the next state (unless OFF is already set)
        void setNextState(int state);
        // converts state into next_state
        virtual bool updateState();
        
private:
        // sets the next state (ignoring the OFF limitation) 
        void forceNextState(int state);
    
};
}    
#endif
