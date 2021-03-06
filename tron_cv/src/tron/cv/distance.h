#ifndef __TRON_CV_DISTANCE_H
#define __TRON_CV_DISTANCE_H

/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *

 ***************************************************************************/

#include "opencv2/core/core.hpp"

namespace tron
{
class Distance
{
public:
    // calculates the squared Euclidean distance between two 2D vectors (byte - byte)
    static int getEuclidean2s (cv::Vec2b& vec1, cv::Vec2b& vec2);
    // calculates the squared Euclidean distance between two 2D vectors (int - int)
    static int getEuclidean2s (cv::Vec2i& vec1, cv::Vec2i& vec2);
    // calculates the squared Euclidean distance between two points (int - int)
    static int getEuclidean2s (cv::Point& p1, cv::Point& p2);

    // calculates the squared Euclidean distance between two 3D vectors (float -float)
    static float getEuclidean3s (cv::Vec3f& vec1, cv::Vec3f& vec2);
    // calculates the squared Euclidean distance between two 3D vectors (float - int)
    static float getEuclidean3s (cv::Vec3f& vec1, cv::Vec3b& vec2);
    // calculates the squared Euclidean distance between two 3D vectors (int - int)
    static int getEuclidean3s (cv::Vec3b& vec1, cv::Vec3b& vec2);


    // calculates the squared Mahalanobis distance between two 2D vectors (int - int), with covariances (cx, cy, cxy)
    static float getMahalanobis2s(cv::Vec2i& vec1, cv::Vec2i& vec2, cv::Vec3f& covs2);
    // calculates the squared Mahalanobis distance between two 2D points, with covariances (cx, cy, cxy)
    static float getMahalanobis2s(cv::Point& p1, cv::Point& p2, cv::Vec3f& covs2);
 
    // calculates the squared Mahalanobis distance between two 3D vectors (float - float), with variances (cx, cy, cz)
    static float getMahalanobis3s(cv::Vec3f& vec1, cv::Vec3f& vec2, cv::Vec3f& covs2);
    // calculates the squared Mahalanobis distance between two 3D vectors (float - int), with variances (cx, cy, cz)
    static float getMahalanobis3s(cv::Vec3f& vec1, cv::Vec3b& vec2, cv::Vec3f& covs2);
};
}

#endif
