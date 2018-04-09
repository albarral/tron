#ifndef __TRON_DISPLAY_DRAW_H
#define __TRON_DISPLAY_DRAW_H

/***************************************************************************
 *   Copyright (C) 2014 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "opencv2/core/core.hpp"

namespace tron
{
// Base class for drawing visual objects (masks, points, ellipses ...) in openCV images
class Draw
{        
public:
    enum eColor{
        eRED, 
        eGREEN,
        eBLUE,                
        eYELLOW, 
        eWHITE,
        eBLACK,
        eCOLORS
    };

protected:
    cv::Scalar color;           // rgb color
    cv::Mat image;          // image drawn 
    bool bsized;            // indicates that image has been sized    
private:
    const float fontSize = 0.2; 
    
public:
    Draw();   
    
    // returns a reference to the drawn image
    cv::Mat& getImage() {return image;};
    
    // Sets the image size
    void setSize(int w, int h);

    // sets the draw image to be a copy of the given image
    void setImage(cv::Mat& image2);

    // clears the drawn image 
    void clear();

    // Sets the color to be used for painting
    void setExactColor(cv::Vec3f&  rgb_color);

    // Draws a mask in the image
    void drawMask(cv::Mat& mask);

    // Draws a mask (roied by a window) in the image
    void drawMask(cv::Mat& mask, cv::Rect& window);

    // Draws a point in the image with the specified color and radius (default green and 3 pixels)
    void drawPoint(cv::Point& point, int radius = 3);

    // Draws a line in the image from point 1 to point 2    
    void drawLine(cv::Point& point1, cv::Point& point2);

    // Draws an ellipse in the image
    void drawEllipse(cv::Point& center, int width, int height, int orientation);

    // Draws a window in the image
    void drawRectangle(cv::Rect& window);

    // Draws an horizontal line in the image
    void drawHLine(int row);

    // Draws a vertical line in the image
    void drawVLine(int col);

    // Draws a number in the image at the specified point. 
    void drawNumber(int num, cv::Point& point);
    void drawFloatNumber(float num, cv::Point& point);
    
    // sets a predefined value for the color
    void setDefaultColor(int value);    
};
}
    
#endif
