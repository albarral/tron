/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tivy/plot/DiscPlot.h"

namespace tivy 
{
DiscPlot::DiscPlot()
{
    // BGR colors
    colorGrey = cv::Scalar(125, 125, 125);
    colorRed = cv::Scalar(0, 0, 255);         
    colorYellow = cv::Scalar(0, 255, 255);
    colorGreen = cv::Scalar(0, 255, 0);
    colorText = cv::Scalar(255, 255, 255);  // white
    // small simple text
    fontFace = cv::FONT_HERSHEY_SIMPLEX;
    fontScale = 0.3;
    thickness = 1;
}

void DiscPlot::initPlot(int w, int h, std::string name)
{
     W=w; 
     H=h; 
     plotName = name;
     
     // disc will be located in center of image
     center.x = 0.5*w;
     center.y = 0.5*h;
     // radius will be 20% of the smaller side
     int min = (w < h ? w : h);
     radius = 0.2*min;
     
     // text will be located upper in the image
     textOrigin.x = 0.4*w;
     textOrigin.y = 0.2*h;     
     
     // create clean image
     image = cv::Mat::zeros(H, W, CV_8UC3);           
}

void DiscPlot::drawDisc(int state)
{
    // prepare image
    image = cv::Scalar(0,0,0);

    // the arm base will be at origin 
    cv::putText(image, plotName, textOrigin, fontFace, fontScale, colorText, thickness, 8);

    switch (state)
    {                 
        case eSTATE_GREY:
            cv::circle(image, center, radius, colorGrey, -1);                   
            break;

        case eSTATE_RED:
            cv::circle(image, center, radius, colorRed, -1);                   
            break;

        case eSTATE_YELLOW:
            cv::circle(image, center, radius, colorYellow, -1);                   
            break;

        case eSTATE_GREEN:
            cv::circle(image, center, radius, colorGreen, -1);                   
            break;
    }
}

}