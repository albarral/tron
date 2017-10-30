#ifndef __TIVY_SHARED_DISPLAY_H
#define __TIVY_SHARED_DISPLAY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <mutex>
#include "opencv2/core/core.hpp"    // for mat

namespace tivy 
{
// This class represents the amy display, which is designed to show multiple plots, each one in a sub-window.
// Thread safety is implemented to allow the drawing and showing of the display be carried by different threads.
// The display composition is the following:
//   -  2 upper windows (in a row)
//   -  2 middle windows (vertically stacked)
//   -  5 bottom windows (in a row).    
class SharedDisplay
{
private:    
        std::mutex mutex;
        // display 
        cv::Mat image;
        std::string windowName;        
        int numBottomWindows;
        // window sizes
        int up_w;
        int up_h;
        int mid_w;
        int mid_h;
        int bot_w;
        int bot_h;
        // display windows
        cv::Rect window_up1;
        cv::Rect window_up2;
        cv::Rect window_mid1;
        cv::Rect window_mid2;
        cv::Rect window_bot[5];
        // display ROIs
        cv::Mat image_up1;
        cv::Mat image_up2;
        cv::Mat image_mid1;
        cv::Mat image_mid2;                        
        cv::Mat image_bot[5];    

public:
    SharedDisplay();       
    ~SharedDisplay();
    
    void initDisplay();
    // update display sub-windows
    void updateDisplayUp1(cv::Mat& img);
    void updateDisplayUp2(cv::Mat& img);
    void updateDisplayMid1(cv::Mat& img);
    void updateDisplayMid2(cv::Mat& img);
    void updateDisplayBot(int num, cv::Mat& img);
    
    // get display measurements
    int getDisplayUpW() {return up_w;}
    int getDisplayUpH() {return up_h;}
    int getDisplayMidW() {return mid_w;}
    int getDisplayMidH() {return mid_h;}
    int getDisplayBotW() {return bot_w;}
    int getDisplayBotH() {return bot_h;}
    
    // show display on screen
    void show();
};
}    
#endif
