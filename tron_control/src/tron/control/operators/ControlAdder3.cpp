/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/operators/ControlAdder3.h"

namespace tron
{
ControlAdder3::ControlAdder3()
{          
    pControl1 = 0; 
    pControl2 = 0; 
    pControl3 = 0; 
    benabled = false;
    value = 0.0;
}

//ControlAdder3::~ControlAdder3 ()
//{
//}

void ControlAdder3::connect(int num, Control3& oControl3)
{
    switch (num)
    {
        case 1: 
            pControl1 = &oControl3;
            break;
        case 2: 
            pControl2 = &oControl3;
            break;
        case 3: 
            pControl3 = &oControl3;
            break;
    }

    benabled = (pControl1 != 0) && (pControl2 != 0) && (pControl3 != 0);
}

bool ControlAdder3::checkRequested()
{	
    // check if some control was requested, update the sum in this case
    if (benabled &&             
            (pControl1->checkRequested() || pControl2->checkRequested() || pControl3->checkRequested()))
    {
        value = pControl1->getValue() + pControl2->getValue() + pControl3->getValue();
        return true;
    }
    else
        return false;
}
}




