#ifndef __TIVY_PLOT_H
#define __TIVY_PLOT_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include "opencv2/core/core.hpp"    // for mat

namespace tivy 
{
// Base class used to plot something in a 2D image (of fixed size) over two orthogonal axes.
class Plot
{
protected:    
    // image
    cv::Mat image;
    std::string plotName;
    // params
    int W;   // plot width (pixels)
    int H;   // plot height (pixels)  
    int margin; // margins applied to plotted image (pixels)
    int xmin;   // min value represented in x axis
    int xmax;   // max value represented in x axis
    int ymin;    // min value represented in y axis
    int ymax;    // max value represented in y axis
    bool bisotropic; // isotropic scaling used (default is false)
    // logic
    float xscale;   // conversion factor to represent x values in image 
    float yscale;   // conversion factor to represent y values in image 
    int x0;           // horizontal position of x origin in image (pixels)
    int y0;           // vertical position of y origin in image (pixels)

public:
    Plot();
     //~Plot();

    // initializes plot with given size (creates image and window)
    void initPlot(int w, int h, std::string name);
    // set plotted ranges (requires scale recomputation)
    void setRanges(int xmin, int xmax, int ymin, int ymax);
    // sets isotropic scaling for the plot
    void setIsotropic(bool bvalue);
    // gets access to plotted image
    cv::Mat& getImage() {return image;};
    
protected:            
    // draws the axes in the plot
    void drawAxes();        
    // checks if given physical point (x,y) is inside the represented ranges
    bool checkRangeLimits(float x, float y);
    // transform the specified physical point (x,y) into its representing plotted point in image
    cv::Point getPoint2Plot(float x, float y);    
    
private:
    // recomputes conversion factor and origin positions
    void updateScale();
};
}    
#endif
