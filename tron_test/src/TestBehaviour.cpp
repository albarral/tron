/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "TestBehaviour.h"

using namespace log4cxx;

LoggerPtr TestBehaviour::logger(Logger::getLogger("tron.test"));

TestBehaviour::TestBehaviour() : tron::Behaviour("TestBehaviour")
{
    addStateName("add");
    addStateName("substract");
    addStateName("multiply");
    addStateName("done");
}

//TestBehaviour::~TestBehaviour()
//{
//}


void TestBehaviour::start()
{
    LOG4CXX_INFO(logger, name << " initialized");          

    // start at sense state
    setState(eSTATE_ADD);    
    number = 0;
    iteration = 0;
}
                    
void TestBehaviour::sense()
{
    iteration++;
    
    if (getState() == eSTATE_DONE)
        return;
    
    if (iteration < 10)
        setState(eSTATE_ADD);    
    else if (iteration < 20)
        setState(eSTATE_SUBSTRACT);    
    else if (iteration < 30)
        setState(eSTATE_MULTIPLY);        
}

void TestBehaviour::think()
{    

    if (isStateChanged())
        showState();
        
    switch (getState())
    {
        case eSTATE_ADD:                     
            number += 10;
            break;

        case eSTATE_SUBSTRACT:            
            number -= 5;
            break;

        case eSTATE_MULTIPLY:            
            number = number * 2;
            break;
    }  

    if (number > 1000)
    {
        setState(eSTATE_DONE);                
        if (isStateChanged())
            showState();
    }
}


void TestBehaviour::actuate()
{
    LOG4CXX_INFO(logger, name << " num = " << number);          
}

void TestBehaviour::end()
{
    LOG4CXX_INFO(logger, name << " finished");          
}

void TestBehaviour::showState()
{
    LOG4CXX_INFO(logger, name << ">> " << getStateName());          
}

