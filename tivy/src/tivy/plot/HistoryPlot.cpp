/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tivy/plot/HistoryPlot.h"

namespace tivy 
{
HistoryPlot::HistoryPlot()
{
    color1 = cv::Scalar(0, 255, 255);  // yellow
    color2 = cv::Scalar(0, 255, 0);  // green
        
    // default values
    timeSpan = 1000;    // 1s
    signalRange = 100;
}
    
void HistoryPlot::setParams(int timeSpan, int signalRange)
{    
    if (timeSpan > 0)
        this->timeSpan = timeSpan;
    
    if (signalRange > 0)
        this->signalRange = signalRange;
}

void HistoryPlot::configDraw(std::string name, int w, int h)
{
    // create a maxSide x 100 window ...
    // able to represent all the signal range in the whole time span (with different scaling for each axis)
    setIsotropic(false);
    initPlot(w, h, name);   
    // negative time till 0
    setRanges(-timeSpan, 0, -signalRange, signalRange);
}

void HistoryPlot::drawHistory(History& oHistory)
{
    int x, y;   // physical values
    cv::Point point; // plotted point
    
    // prepare image
    image = cv::Scalar(0,0,0);
    drawAxes();
    
    std::deque<Record>::iterator it = oHistory.getListRecords().end();
    std::deque<Record>::iterator first = oHistory.getListRecords().begin();
    // walk list from end to beginning
    x = 0;
    while (it != first)
    {
        it--;
        // x is the (negative) accumulated time
        x -= it->etime;
        y = it->signal;

        // draw record point (ignore out of bound points)
        if (checkRangeLimits(x, y))
        {
            // obtain record point in plotted view
            point = getPoint2Plot(x, y);    
            cv::circle(image, point, 1, color1, -1);                   
        }
    }
}

void HistoryPlot::draw2DHistory(History2D& oHistory2D)
{
    int x, y1, y2;   // physical values
    cv::Point point1; // plotted point for signal 1
    cv::Point point2; // plotted point for signal 2
    
    // prepare image
    image = cv::Scalar(0,0,0);
    drawAxes();
    
    std::deque<Record2D>::iterator it = oHistory2D.getListRecords().end();
    std::deque<Record2D>::iterator first = oHistory2D.getListRecords().begin();
    // walk list from end to beginning
    x = 0;
    while (it != first)
    {
        it--;
        // x is the (negative) accumulated time
        x -= it->etime;
        y1 = it->signal1;
        y2 = it->signal2;

        // draw record signal 1 (ignore out of bound points)
        if (checkRangeLimits(x, y1))
        {
            // obtain record point in plotted view
            point1 = getPoint2Plot(x, y1);    
            cv::circle(image, point1, 1, color1, -1);                   
        }
        // draw record signal 2 (ignore out of bound points)
        if (checkRangeLimits(x, y2))
        {
            // obtain record point in plotted view
            point2 = getPoint2Plot(x, y2);    
            cv::circle(image, point2, 1, color2, -1);                   
        }
    }
}
}