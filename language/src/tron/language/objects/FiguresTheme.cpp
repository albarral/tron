/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/language/objects/FiguresTheme.h"
#include "tron/language/TronCategories.h"

namespace tron
{

FiguresTheme::FiguresTheme() : Theme(TronCategories::eCAT_OBJECTS, "figures")
{
    // build theme
    build();    
}

void FiguresTheme::build()
{
    addCode(eFIGURE_CIRCLE, FIGURE_CIRCLE);
    addCode(eFIGURE_ELLIPSE, FIGURE_ELLIPSE);                         
    addCode(eFIGURE_SQUARE, FIGURE_SQUARE);                      
    addCode(eFIGURE_RECTANGLE, FIGURE_RECTANGLE);                   
    addCode(eFIGURE_TRIANGLE, FIGURE_TRIANGLE);                        
    addCode(eFIGURE_LINE, FIGURE_LINE);                        
    addCode(eFIGURE_WAVE, FIGURE_WAVE);                        
}
}