#ifndef __TRON_MATH_MATRIX_H
#define __TRON_MATH_MATRIX_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "opencv2/core/core.hpp"

namespace tron 
{
// Utility class for working with matrices
 class Matrix
{     
 public:         
    // compute correspondences between the elements (rows vs cols) of a given matrix  (float single channel)
    // only the values above the specified threshold are considered
    static void getCorrespondences(cv::Mat mat, float threshold, std::vector<cv::Vec2i>& listCorrespondences);
};  

}  
#endif
