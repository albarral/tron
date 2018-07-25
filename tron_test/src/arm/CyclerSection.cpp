/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include "amy/interface/topics/CyclerSection.h"
#include "arm/CyclerSection.h"
//#include "amy/interface/ArmNode.h"
#include "arm/ArmNode.h"

namespace amy
{

CyclerSection::CyclerSection() : tron::NodeSection(ArmNode::eSECTION_CYCLER1)
{
    oChannelsMap.addCode(eCYCLER_MAIN_FREQ, CYCLER_MAIN_FREQ);
    oChannelsMap.addCode(eCYCLER_MAIN_AMP, CYCLER_MAIN_AMP);                         
    oChannelsMap.addCode(eCYCLER_MAIN_ANGLE, CYCLER_MAIN_ANGLE);                      
    oChannelsMap.addCode(eCYCLER_MAIN_PHASE, CYCLER_MAIN_PHASE);                   
    oChannelsMap.addCode(eCYCLER_SEC_FREQ, CYCLER_SEC_FREQ);
    oChannelsMap.addCode(eCYCLER_SEC_AMP, CYCLER_SEC_AMP);                         
    oChannelsMap.addCode(eCYCLER_SEC_ANGLE, CYCLER_SEC_ANGLE);                      
    oChannelsMap.addCode(eCYCLER_SEC_PHASE, CYCLER_SEC_PHASE);                   
    oChannelsMap.addCode(eCYCLER_ACTION, CYCLER_ACTION);                        
}

}