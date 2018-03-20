/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tivy/DrawnDisplay.h"

namespace tivy 
{
DrawnDisplay::DrawnDisplay()
{
}
    
void DrawnDisplay::init(std::string name, int w, int h)
{
    Display::setName(name);
    Draw::setSize(w, h);
}

void DrawnDisplay::update()
{  
    // show drawn image
    Display::show(image);
}
}