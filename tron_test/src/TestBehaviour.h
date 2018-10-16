#ifndef __TRON_TEST_TESTBEHAVIOUR_H
#define __TRON_TEST_TESTBEHAVIOUR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "tron/control/Behaviour.h"

class TestBehaviour : public tron::Behaviour
{
public:
    // states of the module
    enum eState
    {
         eSTATE_ADD, 
         eSTATE_SUBSTRACT, 
         eSTATE_MULTIPLY,
         eSTATE_DONE,
         eSTATE_DIM
    };
    
protected:    
    static log4cxx::LoggerPtr logger;
    // logic
    int number;
    int iteration;

public:
        TestBehaviour();
        //~TestBehaviour();
                               
private:       
        // things to do when the behavior starts
        virtual void start() override;
        // behavior sense phase
        virtual void sense() override;            
        // behavior actuate phase
        virtual void actuate() override;            
        // things to do when the behavior ends
        virtual void end() override;                     
        
        // shows the present state name
        void showState();
};
#endif
