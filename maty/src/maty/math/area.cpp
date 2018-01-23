/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/area.h"


namespace maty
{
float Area::getWindowOverlap(cv::Rect& window1, cv::Rect& window2)
{
    cv::Rect intersection = window1 & window2;
    
    if (window2.width > 0 && window2.height > 0)
        return (float)(intersection.width * intersection.height) / (float)(window2.width * window2.height);
    else
        return 0.0;
}
}

