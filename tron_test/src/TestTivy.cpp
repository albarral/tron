/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h> // for sleep() 

#include <log4cxx/logger.h>

#include "TestTivy.h"
#include "TestPlot.h"
#include "tivy/SharedDisplay.h"
#include "tivy/history/History.h"
#include "tivy/plot/DiscPlot.h"
#include "tivy/plot/HistoryPlot.h"

using namespace log4cxx;

LoggerPtr TestTivy::logger(Logger::getLogger("tron"));    

// Constructor 
TestTivy::TestTivy()
{    
    modName = "TestTivy";
 }

void TestTivy::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    testPlot();
    //testHistoryPlot();
    //testDiscPlot();    
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
}

void TestTivy::testPlot()
{       
    tivy::SharedDisplay oSharedDisplay;
    TestPlot oTestPlot1;     // test class derived from tivy plot
    TestPlot oTestPlot2;     // test class derived from tivy plot

    oSharedDisplay.initDisplay();
    oTestPlot1.drawLineAndPoint(20, 10);
    oTestPlot2.drawLineAndPoint(-20, 50);
    
    oSharedDisplay.updateDisplayUp1(oTestPlot1.getImage());
    oSharedDisplay.updateDisplayUp2(oTestPlot2.getImage());
    oSharedDisplay.show();
    sleep(4);    
}


void TestTivy::testHistoryPlot()
{
    tivy::SharedDisplay oSharedDisplay;
    tivy::HistoryPlot oHistoryPlot;
    
    oSharedDisplay.initDisplay();
    oHistoryPlot.setParams(400, 100);
    oHistoryPlot.configDraw("histplot", 400, 100);
    
    tivy::History oHistory;
    for (int i=0; i<20; i++)
    {
        float value = 3.0*i;
        oHistory.addRecord(value);
        usleep(100000); // wait 100 ms
    }
    
    oHistoryPlot.drawHistory(oHistory);    
    oSharedDisplay.updateDisplayMid1(oHistoryPlot.getImage());
    oSharedDisplay.show();
    sleep(5);    
}

void TestTivy::testDiscPlot()
{
    tivy::SharedDisplay oSharedDisplay;
    tivy::DiscPlot oDiscPlot;
    
    oSharedDisplay.initDisplay();
    oDiscPlot.initPlot(oSharedDisplay.getDisplayUpW(), oSharedDisplay.getDisplayUpH(), "HS");
        
    oDiscPlot.drawDisc(true);
    oSharedDisplay.updateDisplayUp1(oDiscPlot.getImage());
    oSharedDisplay.show();
    sleep(3);    
    oDiscPlot.drawDisc(false);
    oSharedDisplay.updateDisplayUp1(oDiscPlot.getImage());
    oSharedDisplay.show();
    sleep(3);    
}

