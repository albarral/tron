#ifndef __TRON_MATH_AREA_H
#define __TRON_MATH_AREA_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *

 ***************************************************************************/
#include <opencv2/core/core.hpp>

namespace tron
{
class Area
{
public:
    // Returns the fraction of window2 overlapped by window1
    static float getWindowOverlap(cv::Rect& window1, cv::Rect& window2);

};
}

#endif
