#ifndef __TRON_MATH_DISTANCE2_H
#define __TRON_MATH_DISTANCE2_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *

 ***************************************************************************/

#include <vector>
#include "opencv2/core/core.hpp"

namespace tron
{
class Distance2
{
public:        
    // computes the separation between the given two windows
    static float getWindowsSeparation(cv::Rect& window1, cv::Rect& window2);

    // computes the minimum squared Euclidean distance between two lists of points
    static int getMinEuclidean2s(std::vector<cv::Point>& points1, std::vector<cv::Point>& points2);
    
    // gets the 4 vertices of a given window     
    static std::vector<cv::Point> getWindowVertices(cv::Rect& window);

};
}

#endif
