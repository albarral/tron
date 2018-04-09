/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h> // for sleep() 

#include <log4cxx/logger.h>

#include "TestDisplay.h"
#include "tron/display/DrawnDisplay.h"
#include "tron/display/Chart.h"

using namespace log4cxx;

LoggerPtr TestDisplay::logger(Logger::getLogger("tron"));    

// Constructor 
TestDisplay::TestDisplay()
{    
    modName = "TestTivy";
 }

void TestDisplay::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    //testDrawnDisplay();
    testChart();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
}

void TestDisplay::testDrawnDisplay()
{    
    tron::DrawnDisplay oDrawnDisplay;
    oDrawnDisplay.init("test", 200, 100);
    
    cv::Point point = cv::Point(100, 50);
      
    oDrawnDisplay.drawPoint(point);
    oDrawnDisplay.update();
    sleep(1);    
    point.x += 20;
    
    oDrawnDisplay.drawPoint(point);
    oDrawnDisplay.update();
    sleep(1);    
}

void TestDisplay::testChart()
{    
    tron::Chart oChart;
    oChart.setRanges(200, 100);
    oChart.plotAxes();
    sleep(1);    
    
    cv::Point point = cv::Point(50, 50);      
    oChart.plotPoint(point);
    sleep(1);    

    point.x += 20;
    oChart.plotPoint(point);
    sleep(1);    
}
