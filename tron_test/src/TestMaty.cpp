/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestMaty.h"
#include "maty/math/ArmMath.h"
#include "maty/math/TriangularSignal.h"
#include "maty/signals/Oscillator.h"
#include "maty/signals/SenoidalOscillator.h"

using namespace log4cxx;

LoggerPtr TestMaty::logger(Logger::getLogger("tron"));

// Constructor 
TestMaty::TestMaty()
{    
    modName = "TestMaty";
 }

void TestMaty::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    LOG4CXX_INFO(logger, "\n");
    //testArmMath();
    //testClock();
    //testTriangularSignal();
    testOscillators();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestMaty::testArmMath()
{
    maty::ArmMath oArmMath;
    oArmMath.setLengths(20,80);
    
    float tilt, radius;
    float angleVS, angleEL;

    angleVS = 90; 
    angleEL = -160;
    
    for (int i=0; i<4; i++)
    {
        tilt = oArmMath.computeTilt4JointAngles(angleVS, angleEL);
        radius = oArmMath.computeRadius4ElbowAngle(angleEL);
        LOG4CXX_INFO(logger, "angleVS: " << angleVS << ", angleEL: " << angleEL << ", radius= " << radius << ", tilt= " << tilt << "\n");
        angleVS -= 30;
    }

//    radius = 40;
//    float angle = oArmMath.calcElbowAngle(radius);
//    LOG4CXX_INFO(logger, "radius: " << radius << ", angle = " << angle << "\n");
}

void TestMaty::testClock()
{
    LOG4CXX_INFO(logger, "testClock");

    maty::Clock oClock;
    
    float freq = 50.0;  // 50 Hz
    oClock.setFrequency(freq);

    oClock.reset();    
    for (int i=0; i<61; i++)
    {
        int tics = oClock.update();
        LOG4CXX_INFO(logger, "tics = " << tics << "\n");
        
        usleep(100000);
    }
}

void TestMaty::testTriangularSignal()
{
    LOG4CXX_INFO(logger, "testTriangularSignal");

    maty::Clock oClock;
    oClock.setFrequency(50.0);

    maty::TriangularSignal oTriangularSignal;
    oTriangularSignal.setFrequency(1.0); 

    LOG4CXX_INFO(logger, oTriangularSignal.toString());
    oClock.reset();
    oTriangularSignal.start(oClock);    
    for (int i=0; i<30; i++)
    {
        oClock.update();
        float y = oTriangularSignal.update(oClock);        
        LOG4CXX_INFO(logger, "y = " << y << "\n");
        //LOG4CXX_INFO(logger, "y = " << y << ", sector = " << oSignal.getSector() << ", completion = " << oSignal.getCompletion() << "\n");
        
        usleep(50000);  // 20Hz
    }
}

void TestMaty::testOscillators()
{
    maty::Oscillator oOsc1;
    maty::SenoidalOscillator oOsc2;
    
    float freq = 1.0;
    float span = 2.0;
    // oscillator 1: linear [-1, 1] 
    oOsc1.setFrequency(freq);
    oOsc1.setSpan(span);
    oOsc1.setSymmetry(true);
    // oscillator 2: senoidal  [-1, 1]
    oOsc2.setFrequency(freq);
    
    // reset oscillators
    oOsc1.reset();
    oOsc2.reset();
    
    // run them for 2s
    for (int i=0; i<41; i++)
    {
        oOsc1.update();
        oOsc2.update();        
        LOG4CXX_INFO(logger, "signals = " << oOsc1.getValue() << ", " << oOsc2.getValue2());
        
        usleep(50000);  // 50ms (20Hz)
    }
}