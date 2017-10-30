/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "opencv2/core/core.hpp"    // for cv::Scalar

#include "TestPlot.h"

TestPlot::TestPlot()
{
    // initialize the plot
    int w = 200;
    int h = 200;
    initPlot(w, h, "plot window");   
    int xrange = 100;
    int yrange = 50;
    setRanges(-xrange, xrange, -yrange, yrange);    
}
   
void TestPlot::drawLineAndPoint(int x, int y)
{
    drawAxes();

    cv::Scalar color1 = cv::Scalar(0, 255, 255);  // yellow;
    cv::Scalar color2 = cv::Scalar(0, 255, 0);  // green

    // the line starts at origin 
    cv::Point origin = cv::Point(x0, y0);
    cv::Point endPoint;
    
    // draw line and point 
    if (checkRangeLimits(x, y))
    {
        // obtain point in plotted view
        endPoint = getPoint2Plot(x, y);    
        cv::line(image, origin, endPoint, color1);   
        cv::circle(image, endPoint, 5, color2, -1);                   
    }
}
