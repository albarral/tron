/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestMaty.h"
#include "maty/math/ArmMath.h"
#include "maty/signals/Oscillator.h"
#include "maty/signals/SenoidalOscillator.h"
#include "maty/signals/VectorialOscillator.h"
#include "maty/signals/DualOscillator.h"
#include "tivy/display/Chart.h"
#include "maty/math/Click.h"


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


void TestMaty::testOscillators()
{
    float freq = 0.5;
    float span = 2.0;

    // oscillator 1: linear [-1, 1] 
    maty::Oscillator oOsc;
    oOsc.setFrequency(freq);
    oOsc.setSpan(span);
    oOsc.setSymmetry(true);
    
    // oscillator 2: senoidal  [-1, 1]
    maty::SenoidalOscillator oSenOsc;
    oSenOsc.setFrequency(freq);

    // oscillator 3: vectorial 
    maty::VectorialOscillator oVecOsc;
    oVecOsc.setFrequency(freq);
    oVecOsc.setAmplitude(10.0);
    oVecOsc.setAngle(45);
    
    
    // reset oscillators
    oOsc.reset();
    oSenOsc.reset();
    oVecOsc.reset();
        
    for (int i=0; i<200; i++)
    {
        oOsc.update();
        oSenOsc.update();        
        oVecOsc.update();      
        
        LOG4CXX_INFO(logger, "signal 1 = " << oOsc.getValue() );
        LOG4CXX_INFO(logger, "signal 2 = " << oSenOsc.getValue2());
        LOG4CXX_INFO(logger, "signal 3 = " << oVecOsc.getX() << ", " << oVecOsc.getY());
        
        usleep(50000);  // 50ms (20Hz)
    }
}

void TestMaty::testDualOscillator()
{    
    // use dual oscillator to get oscillating speed
    float freq = 0.5;
    float angle = 180;
    float speed = 0.1;
    maty::DualOscillator oDualOsc;
    oDualOsc.setPrimaryFreq(freq);
    oDualOsc.setPrimaryAmp(speed);
    oDualOsc.setPrimaryAngle(angle);
    // secondary oscillator is orthogonal to first one
    oDualOsc.setSecondaryFreq(freq);
    oDualOsc.setSecondaryAmp(speed);
    oDualOsc.setSecondaryAngle(angle+90.0);
    oDualOsc.setSecondaryPhase(90);

    maty::Click oClick;
    tivy::Chart oChart;
    oChart.setRanges(100, 100);
    oChart.plotAxes();
    
    // reset oscillator
    oDualOsc.reset();
    oClick.reset();
        
    cv::Vec2f pos = {0.0, 0.0};
    int time = 0;
    cv::Point point;
    for (int i=0; i<200; i++)
    {
        oDualOsc.update();

        oClick.read();
        oClick.start();
        time = oClick.getMillis();
        
        LOG4CXX_INFO(logger, "signal 4 = " << oDualOsc.getX() << ", " << oDualOsc.getY());
        
        // apply present speed value
        pos[0] += oDualOsc.getX()*time;
        pos[1] += oDualOsc.getY()*time;
        point.x = pos[0];
        point.y = pos[1];

        oChart.plotPoint(point, true);
        
        usleep(50000);  // 50ms (20Hz)
    }
}