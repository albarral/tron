/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
  ***************************************************************************/

#include "tron/cv/Distance2.h"
#include "tron/cv/distance.h"

namespace tron
{
float Distance2::getWindowsSeparation(cv::Rect& window1, cv::Rect& window2)
{
    // get intersection of windows
    cv::Rect intersection = window1 & window2;     
    
    // case 1: windows overlap -> separation 0
    if (intersection.width > 0)  
        return 0.0;
    else
    {
        float sep;
        cv::Rect wunion = window1 | window2;     
        
        // case 2A: windows overlap vertically (in x plane) -> separation = y distance
        if (wunion.width < window1.width + window2.width)
        {
            int bottom1, top2;
            // window1 is over window2
            if (window2.y > window1.y)
            {
                bottom1 = window1.y + window1.height;
                top2 = window2.y;
            }
            // window2 is over window1
            else
            {
                bottom1 = window2.y + window2.height;
                top2 = window1.y;
            }
            sep = top2 - bottom1; 
        }
        // case 2B: windows overlap horizontally (in y plane) -> separation = x distance
        else if (wunion.height < window1.height + window2.height)
        {
            int rightBorder1, leftBorder2;
            // window2 comes after window1
            if (window2.x > window1.x)
            {
                rightBorder1 = window1.x + window1.width;
                leftBorder2 = window2.x;
            }
            // window1 comes after window2
            else
            {
                rightBorder1 = window2.x + window2.width;
                leftBorder2 = window1.x;
            }
            sep = leftBorder2 - rightBorder1; 
        }        
        // case 3: windows don't overlap in any plane -> separation = minimum distance between vertices
        else
        {        
            std::vector<cv::Point> vertices1 = getWindowVertices(window1);
            std::vector<cv::Point> vertices2 = getWindowVertices(window2);

            // compute minimum distance between both windows vertices
            sep = sqrt(getMinEuclidean2s(vertices1, vertices2));
        }
        return sep;
    }
}
    
int Distance2::getMinEuclidean2s(std::vector<cv::Point>& points1, std::vector<cv::Point>& points2)
{
    int minSqrDist = 10000;
    int sqrDist;
    for (cv::Point point1 : points1)
        for (cv::Point point2 : points2)
        {
            sqrDist = Distance::getEuclidean2s(point1, point2);
            if (sqrDist < minSqrDist)
                minSqrDist = sqrDist;            
        }

    return minSqrDist;
}

std::vector<cv::Point> Distance2::getWindowVertices(cv::Rect& window)
{
    int right = window.x + window.width;
    int bottom = window.y + window.height;
    std::vector<cv::Point> vertices = {cv::Point(window.x, window.y), cv::Point(right, window.y), cv::Point(window.x, bottom), cv::Point(right, bottom)};
    return vertices;
}

}
