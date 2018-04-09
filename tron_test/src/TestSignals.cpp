/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestSignals.h"
#include "tron/signals/Oscillator.h"
#include "tron/signals/SenoidalOscillator.h"
#include "tron/signals/VectorialOscillator.h"
#include "tron/signals/DualOscillator.h"
#include "tron/display/Chart.h"
#include "tron/util/Click.h"


using namespace log4cxx;

LoggerPtr TestSignals::logger(Logger::getLogger("tron"));

// Constructor 
TestSignals::TestSignals()
{    
    modName = "TestSignals";
 }

void TestSignals::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    LOG4CXX_INFO(logger, "\n");
    //testOscillators();
    testDualOscillator();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestSignals::testOscillators()
{
    float freq = 0.5;
    float span = 2.0;

    // oscillator 1: linear [-1, 1] 
    tron::Oscillator oOsc;
    oOsc.setFrequency(freq);
    oOsc.setSpan(span);
    oOsc.setSymmetry(true);
    
    // oscillator 2: senoidal  [-1, 1]
    tron::SenoidalOscillator oSenOsc;
    oSenOsc.setFrequency(freq);

    // oscillator 3: vectorial 
    tron::VectorialOscillator oVecOsc;
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

void TestSignals::testDualOscillator()
{    
    // use dual oscillator to get oscillating speed
    float freq = 0.5;
    float angle = 180;
    float speed = 0.1;
    tron::DualOscillator oDualOsc;
    oDualOsc.setPrimaryFreq(freq);
    oDualOsc.setPrimaryAmp(speed);
    oDualOsc.setPrimaryAngle(angle);
    // secondary oscillator is orthogonal to first one
    oDualOsc.setSecondaryFreq(freq);
    oDualOsc.setSecondaryAmp(speed);
    oDualOsc.setSecondaryAngle(angle+90.0);
    oDualOsc.setSecondaryPhase(90);

    tron::Click oClick;
    tron::Chart oChart;
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