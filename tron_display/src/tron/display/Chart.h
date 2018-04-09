#ifndef __TRON_DISPLAY_CHART_H
#define __TRON_DISPLAY_CHART_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "opencv2/core/core.hpp"   

#include "tron/display/DrawnDisplay.h"

namespace tron 
{
// Class used to display charts. It's a DrawnDisplay with coordinate axes representing a range in which physical points can be plotted.
// Both ranges are symmetrical, and the representation uses isotropic scaling.
// The image size is prefixed at 400x200. 
class Chart: public DrawnDisplay
{
private:    
    const int W = 400;   // image width (pixels)
    const int H = 200;   // image height (pixels)  
    const int margin = 10; // margins applied represented range (pixels)
    cv::Point min;   // minimum physical values represented in x and y axis
    cv::Point max;   // maximum physical values represented in x and y axis
    // logic
    cv::Mat imageBackground;  // background image (with only the axes plotted)
    cv::Point origin;   // position of axis origin in image (pixels)    
    float scale;        // (isotropic) conversion factor to represent physical points in the image 

public:
    Chart();
     //~Chart();

    // set the represented physical ranges (symmetric ranges)
    void setRanges(int xmax, int ymax);    
    // draws the axes in the plot
    void plotAxes();        
    // plots the specified physical point in the display (renewing the image if necessary)
    bool plotPoint(cv::Point& point, bool brenew=false);
    
private:            
    // checks if given physical point (x,y) is inside the represented ranges
    bool checkRangeLimits(cv::Point& point);
    // transform a physical point into its represented point in the image
    cv::Point physical2Chart(cv::Point& point);    
};
}    
#endif
