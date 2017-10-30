/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <opencv2/highgui/highgui.hpp>  // for named window

#include "tivy/SharedDisplay.h"

namespace tivy 
{
SharedDisplay::SharedDisplay()
{
    windowName = "amy display";
    numBottomWindows = 5;      // 5 bottom windows
    up_w = 200;
    up_h = 200;
    mid_w = 400;
    mid_h = 100;
    bot_w = mid_w/numBottomWindows; 
    bot_h = 50;
}
    
SharedDisplay::~SharedDisplay()
{    
    // hide window
    cv::destroyWindow(windowName);
}

// create display image and sub-windows
void SharedDisplay::initDisplay()
{
    std::lock_guard<std::mutex> locker(mutex);

    // compute display width (max of windows widths)
    int W = 2*up_w;
    if (W < mid_w)
        W = mid_w;
    if (W < bot_w)
        W = bot_w;    
    // compute display height (sum of windows heights)
    int H = up_h + 2*mid_h + bot_h;
    
    // create the display image (clean)    
    image = cv::Mat::zeros(H, W, CV_8UC3);           
     
     // create upper windows
    int x=0; 
    int y=0;
    window_up1 = cv::Rect(x, y, up_w, up_h);
    x = window_up1.width;
    window_up2 = cv::Rect(x, y, up_w, up_h);
    // create middle windows
    x = 0; 
    y = window_up1.height;
    window_mid1 = cv::Rect(x, y, mid_w, mid_h);
    y += window_mid1.height;
    window_mid2 = cv::Rect(x, y, mid_w, mid_h);
    // create 5 bottom windows
    x = 0; 
    y += window_mid2.height;
    for (int i=0; i<numBottomWindows; i++)
    {
        window_bot[i] = cv::Rect(x, y, bot_w, bot_h);
        x += bot_w;        
    }

    // create display ROIs
    image_up1 = image(window_up1);
    image_up2 = image(window_up2);
    image_mid1 = image(window_mid1);
    image_mid2 = image(window_mid2);
    for (int i=0; i<numBottomWindows; i++)
    {
        image_bot[i] = image(window_bot[i]);
    }

    // create display window
    cv::namedWindow(windowName);              
}

void SharedDisplay::updateDisplayUp1(cv::Mat& img)
{  
    std::lock_guard<std::mutex> locker(mutex);
    
    img.copyTo(image_up1);
}

void SharedDisplay::updateDisplayUp2(cv::Mat& img)
{  
    std::lock_guard<std::mutex> locker(mutex);
    
    img.copyTo(image_up2);
}

void SharedDisplay::updateDisplayMid1(cv::Mat& img)
{  
    std::lock_guard<std::mutex> locker(mutex);
    
    img.copyTo(image_mid1);
}

void SharedDisplay::updateDisplayMid2(cv::Mat& img)
{  
    std::lock_guard<std::mutex> locker(mutex);
    
    img.copyTo(image_mid2);
}

void SharedDisplay::updateDisplayBot(int num, cv::Mat& img)
{  
    std::lock_guard<std::mutex> locker(mutex);
    
    if (num>= 0 && num<numBottomWindows)
        img.copyTo(image_bot[num]);
}

void SharedDisplay::show()
{
    std::lock_guard<std::mutex> locker(mutex);
  
    // show plot
    cv::imshow(windowName, image);
    cv::waitKey(100);    
}

}