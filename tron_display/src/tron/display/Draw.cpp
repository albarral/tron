/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/display/Draw.h"

namespace tron
{
// Constructor
Draw::Draw ()
{    
    color = cv::Scalar(255, 255, 255);  // white
    bsized = false;
}


void Draw::setSize(int w, int h)
{     
    image = cv::Mat::zeros(h, w, CV_8UC3);           
    bsized = true;    
}


void Draw::setImage(cv::Mat& image2)
{      
    if (!bsized)        
        setSize(image2.cols, image2.rows);

    image2.copyTo(image);
}


void Draw::clear()
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }
        
    image.setTo(cv::Scalar(0));
}


void Draw::setExactColor(cv::Vec3f& rgb_color)
{
    color = cv::Scalar(rgb_color[2], rgb_color[1], rgb_color[0]);      // BGR
}


void Draw::drawMask(cv::Mat& mask)
{                
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }

    image.setTo(color, mask);
}


void Draw::drawMask(cv::Mat& mask, cv::Rect& window)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }

    cv::Mat image_roi = image(window);
    image_roi.setTo(color, mask);
}


void Draw::drawPoint(cv::Point& point, int radius)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }

    cv::circle(image, point, radius, color, -1);
}


void Draw::drawLine(cv::Point& point1, cv::Point& point2)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }

    cv::line(image, point1, point2, color);
}

void Draw::drawEllipse(cv::Point& center, int width, int height, int orientation)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }
    
    cv::ellipse (image, center, cv::Size(width, height), orientation, 0, 360, color, 3);
}


void Draw::drawRectangle(cv::Rect& window)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }
    
    cv::rectangle(image, window, color);
}


void Draw::drawHLine(int row)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }

    cv::Point pt1(0, row);
    cv::Point pt2(image.cols-1, row);
    cv::line(image, pt1, pt2, color);    
}

        
void Draw::drawVLine(int col)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }

    cv::Point pt1(col, 0);
    cv::Point pt2(col, image.rows-1);
    cv::line(image, pt1, pt2, color);    
}


void Draw::drawNumber(int num, cv::Point& point)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }
    cv::putText(image, std::to_string(num), point, cv::FONT_HERSHEY_SIMPLEX, fontSize, color);
}

void Draw::drawFloatNumber(float num, cv::Point& point)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }
    // just show one decimal digit
    std::string text = std::to_string(num);
    text = text.substr(0,3);
    cv::putText(image, text, point, cv::FONT_HERSHEY_SIMPLEX, fontSize, color, 2);
}

void Draw::drawText(std::string text, cv::Point& point)
{
    if (!bsized)
    {
        std::cout << "Draw error: image still not created" << std::endl;
        return;
    }
    cv::putText(image, text, point, cv::FONT_HERSHEY_SIMPLEX, fontSize, color, 2);
}

void Draw::setDefaultColor(int value)
{
    // sets BGR color
    switch (value)
    {
        case eRED:
            color = cv::Scalar(0, 0, 255);
            break;            
        case eGREEN:
            color = cv::Scalar(0, 255, 0);
            break;
        case eBLUE:
            color = cv::Scalar(255, 0, 0);
            break;            
        case eYELLOW:
            color = cv::Scalar(0, 255, 255);
            break;
        case eWHITE:
            color = cv::Scalar(255, 255, 255);
            break;
        case eBLACK:
            color = cv::Scalar(0, 0, 0);
            break;
    }
}

cv::Point Draw::getCardinalPoint(int cardinal)
{
    int w = image.cols; 
    int h = image.rows;
    // image y axis faces down
    switch (cardinal)
    {
        case ePOINT_NORTH: 
            return cv::Point(w/2, 0);
        case ePOINT_SOUTH:  
            return cv::Point(w/2, h-1);
        case ePOINT_EAST: 
            return cv::Point(w-1, h/2);
        case ePOINT_WEST:
            return cv::Point(0, h/2);
        case ePOINT_NORTH_EAST: 
            return cv::Point(w-1, 0);
        case ePOINT_NORTH_WEST:
            return cv::Point(0, 0);
        case ePOINT_SOUTH_EAST: 
            return cv::Point(w-1, h-1);
        case ePOINT_SOUTH_WEST: 
            return cv::Point(0, h-1);
        case ePOINT_CENTER: 
            return cv::Point(w/2, h/2);        
        // invalid cardinal point    
        default: 
            return cv::Point(-1, -1);
    }
}
}
