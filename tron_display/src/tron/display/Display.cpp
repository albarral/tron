/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <opencv2/highgui/highgui.hpp>  // for named window

#include "tron/display/Display.h"

namespace tron 
{
Display::Display()
{
    windowName = "display";
    bshowing = false;
}
    
Display::~Display()
{    
    hide();
}

void Display::setName(std::string value)
{
    if (!value.empty())
        windowName = value;
}

void Display::show(cv::Mat& image)
{
    if (!bshowing)
    {
        // create display window
        cv::namedWindow(windowName);              
        bshowing = true;
    }

    // show plot
    cv::imshow(windowName, image);
    cv::waitKey(1);    
}

void Display::hide()
{  
    if (bshowing)
    {
        // hide window
        cv::destroyWindow(windowName);        
        bshowing = false;
    }
}

}