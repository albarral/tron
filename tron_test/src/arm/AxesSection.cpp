/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include "amy/interface/topics/AxesSection.h"
#include "arm/AxesSection.h"
//#include "amy/interface/ArmNode.h"
#include "arm/ArmNode.h"

namespace amy
{

AxesSection::AxesSection() : tron::NodeSection(ArmNode::eSECTION_AXES)
{
    oChannelsMap.addCode(eAXES_PAN, AXES_PAN);
    oChannelsMap.addCode(eAXES_TILT, AXES_TILT);                         
    oChannelsMap.addCode(eAXES_RAD, AXES_RAD);                      
    oChannelsMap.addCode(eAXES_PAN_SPEED, AXES_PAN_SPEED);                   
    oChannelsMap.addCode(eAXES_TILT_SPEED, AXES_TILT_SPEED);                        
    oChannelsMap.addCode(eAXES_RAD_SPEED, AXES_RAD_SPEED);                        
    oChannelsMap.addCode(eAXES_KEEP_TILT, AXES_KEEP_TILT);                         
}
}