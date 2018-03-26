#ifndef __TRON_LANGUAGE_FIGURESTHEME_H
#define __TRON_LANGUAGE_FIGURESTHEME_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/language/Theme.h"

namespace tron
{
// Theme for figures (objects category)
 class FiguresTheme : public Theme
{
 public:
    /*! theme codes  */
    enum eCodes
    {
         eFIGURE_CIRCLE,                       
         eFIGURE_ELLIPSE,                       
         eFIGURE_SQUARE,                       
         eFIGURE_RECTANGLE,                    
         eFIGURE_TRIANGLE,                    
         eFIGURE_LINE,                    
         eFIGURE_WAVE,                    
         eFIGURE_DIM
    };

    /*! code names */
    const std::string FIGURE_CIRCLE = "circle";     
    const std::string FIGURE_ELLIPSE = "ellipse";       
    const std::string FIGURE_SQUARE = "square";      
    const std::string FIGURE_RECTANGLE = "rectangle"; 
    const std::string FIGURE_TRIANGLE = "triangle";   
    const std::string FIGURE_LINE = "line";  
    const std::string FIGURE_WAVE = "wave";  

 public:    
    FiguresTheme(); 

    // build theme
    virtual void build();    
};
}
#endif
