#ifndef __TIVY_DISCPLOT_H
#define __TIVY_DISCPLOT_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include "opencv2/core/core.hpp"    

namespace tivy 
{
// Class used to plot a colored disc in a 2D image.
class DiscPlot 
{
public:    
    // disc states
    enum eState
    {
         eSTATE_GREY,              // grey disk
         eSTATE_RED,                // red disk
         eSTATE_YELLOW,          // yellow disk
         eSTATE_GREEN             // green disk
    };

private:    
    cv::Mat image;
    // params
    int W;   // plot width (pixels)
    int H;   // plot height (pixels)  
    std::string plotName;
    // logic
    cv::Point center;           // disc center
    int radius;                   // disc radius (pixels)
    // colors for disk & text
    cv::Scalar colorGrey;     
    cv::Scalar colorRed;     
    cv::Scalar colorYellow;     
    cv::Scalar colorGreen;   
    cv::Scalar colorText;    
    // text configuration
    cv::Point textOrigin;       // origin position for the text
    int fontFace;
    double fontScale;
    int thickness;

public:
    DiscPlot();
     //~DiscPlot();

    // initializes plot with given size (creates image and window)
    void initPlot(int w, int h, std::string name);    
    // gets access to plotted image
    cv::Mat& getImage() {return image;};

    // draws disc representing the given state (one of eStates)
    void drawDisc(int state);
};
}    
#endif
