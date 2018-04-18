#ifndef __TRON_CONTROL_CONTROLADDER3_H
#define __TRON_CONTROL_CONTROLADDER3_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/control/brooks/control3.h"

namespace tron
{
// This class is an operator that adds the outputs of 3 control connectors.
class ControlAdder3
{
private:
    Control3* pControl1;    // access to 1st control connector
    Control3* pControl2;    // access to 2nd control connector
    Control3* pControl3;    // access to 3rd control connector
    bool benabled;
    float value;                  // sum of control values

public:
    ControlAdder3();
    //~ControlAdder3();
        
    // set control connection
    void connect(int num, Control3& oControl3);
    
    bool checkRequested();
    
    float getValue() {return value;};
};

}  

#endif
