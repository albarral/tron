#ifndef __TRON_TESTPLOT_H
#define __TRON_TESTPLOT_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tivy/plot/Plot.h"

// Testing of a tivy plot derived class.
class TestPlot : public tivy::Plot
{
public:
    TestPlot();
     //~TestPlot();
    
    // draws a line from axes origin to given point in space
    void drawLineAndPoint(int x, int y);
};
#endif
