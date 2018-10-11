/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestControl.h"

#include "tron/control/brooks/control2.h"
#include "tron/control/brooks/control3.h"
#include "tron/control/brooks/sensor2.h"
#include "tron/control/brooks/sensor3.h"
#include "tron/control/operators/ControlAdder3.h"
#include "tron/control/Module4.h"
#include "TestBehaviour.h"

using namespace log4cxx;

LoggerPtr TestControl::logger(Logger::getLogger("tron"));

// Constructor 
TestControl::TestControl()
{    
    modName = "TestControl";
 }

void TestControl::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

//    testControls();
//    testSensors();
//    testAdder();
    testModule4();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestControl::testControls()
{
    LOG4CXX_INFO(logger, modName + ": testControls ...");
    
    tron::Control2 CO_NUM;
    tron::Control3 CO_SPEED;

    CO_NUM.request(10);
    CO_SPEED.request(56.1);
    
    int value2;
    if (CO_NUM.checkRequested())
        value2 = CO_NUM.getValue();        
    else
        value2 = -1;

    float value3; 
    if (CO_SPEED.checkRequested())
        value3 = CO_SPEED.getValue();        
    else
        value3 = -1;
       
    LOG4CXX_INFO(logger, modName + ": num received = " << value2);                            
    LOG4CXX_INFO(logger, modName + ": speed received = " << value3);                            
}

void TestControl::testSensors()
{
    LOG4CXX_INFO(logger, modName + ": testSensors ...");
    
    tron::Sensor2 SO_NUM;
    tron::Sensor3 SO_SPEED;

    SO_NUM.setValue(10);
    SO_SPEED.setValue(56.1);
    
    int value2 = SO_NUM.getValue();        
    float value3 = SO_SPEED.getValue();        
       
    LOG4CXX_INFO(logger, modName + ": num received = " << value2);                            
    LOG4CXX_INFO(logger, modName + ": speed received = " << value3);                            
}

void TestControl::testAdder()
{
    LOG4CXX_INFO(logger, modName + ": testAdder ...");
    
    float value = -1;
    tron::Control3 CO_SPEED1;
    tron::Control3 CO_SPEED2;
    tron::Control3 CO_SPEED3;    
    tron::ControlAdder3 CO_ADDER;

    CO_ADDER.connect(1, CO_SPEED1);
    CO_ADDER.connect(2, CO_SPEED2);
    CO_ADDER.connect(3, CO_SPEED3);

    CO_SPEED1.request(10.1);
    CO_SPEED2.request(20.2);
    CO_SPEED3.request(30.3);
    

    if (CO_ADDER.checkRequested())
        value = CO_ADDER.getValue();               
    LOG4CXX_INFO(logger, modName + ": adder value = " << value);                            
    
    CO_SPEED3.request(60.6);
    if (CO_ADDER.checkRequested())
        value = CO_ADDER.getValue();               
    LOG4CXX_INFO(logger, modName + ": adder value = " << value);                            
    
}

void TestControl::testModule4()
{
    LOG4CXX_INFO(logger, modName + ": testModule4 ...");
    
    TestBehaviour oTestBehaviour;
    
    tron::Module4 oModule;
    oModule.setBehaviour(oTestBehaviour);
    oModule.setFrequency(5.0);
    
    oModule.on();
    
    usleep(7*1000000);
    
    oModule.off();
    oModule.wait();    
}
