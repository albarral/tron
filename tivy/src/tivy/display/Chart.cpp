/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tivy/display/Chart.h"

namespace tivy 
{
Chart::Chart()
{
    // set display name and sizes
    init("Chart", W, H);
    setRanges(50, 50);    
}
    
void Chart::setRanges(int xmax, int ymax)
{
    // skip if invalid ranges specified
    if ((xmax <= 0) || (ymax <= 0))
        return;
    
    min.x = -xmax;
    min.y = -ymax;
    max.x = xmax;
    max.y = ymax;
    
    float xscale = (float)(W - 2*margin) / (max.x - min.x);
    float yscale = (float)(H - 2*margin) / (max.y - min.y);
    
    // use same scale factor for both axes (the smaller to assure the complete representation of both ranges)
    scale = (xscale < yscale ? xscale : yscale);

    // compute origin position in image
//    origin.x = margin + abs(min.x)*scale;
//    origin.y = margin + abs(min.y)*scale;    
    origin.x = W/2;
    origin.y = H/2;    
}

void Chart::plotAxes()
{
    Draw::setDefaultColor(Draw::eRED);
    // set axes physical limits
    cv::Point left = cv::Point(min.x, 0);
    cv::Point right = cv::Point(max.x, 0);
    cv::Point top = cv::Point(0, max.y);
    cv::Point bottom = cv::Point(0, min.y);
    // transform them to char points
    cv::Point left2 = physical2Chart(left);
    cv::Point right2 = physical2Chart(right);
    cv::Point top2 = physical2Chart(top);
    cv::Point bottom2 = physical2Chart(bottom);        
    // draw x axis
    Draw::drawLine(left2, right2); 
    // draw y axis
    Draw::drawLine(top2, bottom2); 

    Draw::setDefaultColor(Draw::eYELLOW);
    // draw axes limits 
    Draw::drawNumber(min.x, left2);
    Draw::drawNumber(max.x, right2);
    Draw::drawNumber(min.y, bottom2);
    Draw::drawNumber(max.y, top2);
    
    imageBackground = image.clone();

    // update display
    update();

    Draw::setDefaultColor(Draw::eWHITE);
}

bool Chart::plotPoint(cv::Point& point, bool brenew)
{
    if (brenew)
    {
        imageBackground.copyTo(image);
    }
    
    // if point is inside represented range
    if (checkRangeLimits(point))
    {
        // transform it and plot it
        cv::Point point2 = physical2Chart(point);
        Draw::drawPoint(point2);           
        // update display
        update();
        return true;
    }
    else
        return false;        
}

// checks if given physical point (x,y) is inside the represented ranges
bool Chart::checkRangeLimits(cv::Point& point)
{
    return (point.x>=min.x && point.x<=max.x && point.y>=min.y && point.y<=max.y);
}

// transform the specified physical point (x,y) into its representing plotted point in image
cv::Point Chart::physical2Chart(cv::Point& point)
{
    return cv::Point(origin.x + point.x*scale, H - (origin.y + point.y*scale));  // draw upside-down
}
}