#ifndef __TRON_LANGUAGE_DIRECTIONSTHEME_H
#define __TRON_LANGUAGE_DIRECTIONSTHEME_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/language/Theme.h"

namespace tron
{
// Theme for directions (features category)
 class DirectionsTheme : public Theme
{
 public:
    /*! theme codes  */
    enum eCodes
    {
         eDIRECTION_UP,                       
         eDIRECTION_DOWN,                       
         eDIRECTION_LEFT,                       
         eDIRECTION_RIGHT,                    
         eDIRECTION_FRONT,                    
         eDIRECTION_BACK,                    
         eDIRECTION_DIM
    };

    /*! code names */
    const std::string DIRECTION_UP = "up";     
    const std::string DIRECTION_DOWN = "down";       
    const std::string DIRECTION_LEFT = "left";      
    const std::string DIRECTION_RIGHT = "right"; 
    const std::string DIRECTION_FRONT = "front";   
    const std::string DIRECTION_BACK = "back";  

 public:    
    DirectionsTheme(); 

    // build theme
    virtual void build();    
};
}
#endif
