#ifndef __TRON_DISPLAY_DISPLAY_H
#define __TRON_DISPLAY_DISPLAY_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include "opencv2/core/core.hpp"    // for mat

namespace tron 
{
// Base class to display images in GUI windows.
class Display
{
private:    
        // display 
        std::string windowName;        
        bool bshowing;        

public:
    Display();       
    ~Display();
    
    void setName(std::string value);
    
    // show display on screen
    void show(cv::Mat& image);
    // hide display
    void hide();
};
}    
#endif
