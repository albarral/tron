#ifndef __TRON_CONTROL_BEHAVIOUR_H
#define __TRON_CONTROL_BEHAVIOUR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

namespace tron
{
// Base class for implementing robot behaviours.
// Designed to implement FSM (finite state machines).
class Behaviour 
{
protected:
        std::string name;   // behaviour name
private:        
        int state;             // module's present state
        int prevState;       // module's previous state
        bool binhibited;        // inhibited flag (when true no work is done by the methods)
        std::vector<std::string> listStateNames;    // state names 

public:
        Behaviour();
        Behaviour(std::string name);
        ~Behaviour();
                
        // get behavior name
        std::string getName() {return name;};
        // get behavior state
        int getState() {return state;};
        // get behavior previous state
        int getPrevState() {return prevState;};
        // checks if state has changed in last loop
        bool isStateChanged() {return (state != prevState);};
        // get inhibited flag
        bool isInhibited() {return binhibited;};
        // get copy of state names
        std::vector<std::string> getStateNames() {return listStateNames;};
        // get name of present behavior state
        std::string getStateName();

        // set behavior state 
        void setState(int value) {state = value;};
        // inhibit behavior
        void inhibit(bool value) {binhibited = value;}; 
        // add state name
        void addStateName(std::string name);

        // TO IMPLEMENT BY REAL BEHAVIOURS ...        
        // things to do when the behavior starts
        virtual void start() = 0;
        // behavior sense phase
        virtual void sense() = 0;            
        // behavior actuate phase
        virtual void actuate() = 0;            
        // things to do when the behavior ends
        virtual void end() = 0;                       

        // done before each loop iteration
        void preLoop();
};
}    
#endif
