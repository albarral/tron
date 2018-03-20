/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/ArmClient.h"
#include "tron/talky2/arm/JointTalker.h"
#include "tron/talky2/arm/AxisTalker.h"
#include "tron/talky2/arm/CyclicTalker.h"
#include "tron/talky2/BasicTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr ArmClient::logger(Logger::getLogger("tron.talky2"));

ArmClient::ArmClient()
{    
    int node = RobotNodes::eNODE_ARM;
    pJointChannelClient = new ChannelClient(node, ArmTopics::eARM_JOINT);
    pAxisChannelClient = new ChannelClient(node, ArmTopics::eARM_AXIS);
    pCyclicChannelClient = new ChannelClient(node, ArmTopics::eARM_CYCLIC);
    pExtraChannelClient = new ChannelClient(node, ArmTopics::eARM_EXTRA);
}

ArmClient::~ArmClient()
{    
    if (pJointChannelClient != 0)
        delete(pJointChannelClient);
    if (pAxisChannelClient != 0)
        delete(pAxisChannelClient);
    if (pCyclicChannelClient != 0)
        delete(pCyclicChannelClient);
    if (pExtraChannelClient != 0)
        delete(pExtraChannelClient);
}

// JOINT TOPIC ...

bool ArmClient::setHS(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set HS > " << std::to_string(value));
    return pJointChannelClient->sendMessage(JointTalker::eJOINT_HS_POS, value);
}

bool ArmClient::setVS(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set VS > " << std::to_string(value));
    return pJointChannelClient->sendMessage(JointTalker::eJOINT_VS_POS, value);
}

bool ArmClient::setELB(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set ELB > " << std::to_string(value));
    return pJointChannelClient->sendMessage(JointTalker::eJOINT_ELB_POS, value);
}

bool ArmClient::setHWRI(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set HWRI > " << std::to_string(value));
    return pJointChannelClient->sendMessage(JointTalker::eJOINT_HWRI_POS, value);
}

bool ArmClient::setVWRI(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set VWRI > " << std::to_string(value));
    return pJointChannelClient->sendMessage(JointTalker::eJOINT_VWRI_POS, value);
}

// AXIS TOPIC ...

bool ArmClient::setPan(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set pan > " << std::to_string(value));
     return pAxisChannelClient->sendMessage(AxisTalker::eAXIS_PAN_POS, value);
}

bool ArmClient::setTilt(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set tilt > " << std::to_string(value));
     return pAxisChannelClient->sendMessage(AxisTalker::eAXIS_TILT_POS, value);
}

bool ArmClient::setRadial(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set radius > " << std::to_string(value));
     return pAxisChannelClient->sendMessage(AxisTalker::eAXIS_RAD_POS, value);
}

bool ArmClient::setPanSpeed(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set pan speed > " << std::to_string(value));
     return pAxisChannelClient->sendMessage(AxisTalker::eAXIS_PAN_SPEED, value);
}

bool ArmClient::setTiltSpeed(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set tilt speed > " << std::to_string(value));
     return pAxisChannelClient->sendMessage(AxisTalker::eAXIS_TILT_SPEED, value);
}

bool ArmClient::setRadialSpeed(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set radial speed > " << std::to_string(value));
     return pAxisChannelClient->sendMessage(AxisTalker::eAXIS_RAD_SPEED, value);
}

bool ArmClient::keepTilt()
{
    LOG4CXX_DEBUG(logger, "ArmClient: keep tilt > ");     
    return pAxisChannelClient->sendMessage(AxisTalker::eAXIS_KEEP_TILT, 0.0);        
}

// CYCLIC TOPIC ...

bool ArmClient::setFrontCyclerAmp1(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler amp1 > " << std::to_string(value));     
    return pCyclicChannelClient->sendMessage(CyclicTalker::eCYCLIC_FRONT1_AMP, value);    
}

bool ArmClient::setFrontCyclerAngle1(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler angle1 > " << std::to_string(value));     
    return pCyclicChannelClient->sendMessage(CyclicTalker::eCYCLIC_FRONT1_ANGLE, value);    
}

bool ArmClient::setFrontCyclerFreq1(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler freq1 > " << std::to_string(value));     
    return pCyclicChannelClient->sendMessage(CyclicTalker::eCYCLIC_FRONT1_FREQ, value);    
}

bool ArmClient::setFrontCyclerPhase1(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler phase1 > " << std::to_string(value));     
    return pCyclicChannelClient->sendMessage(CyclicTalker::eCYCLIC_FRONT1_PHASE, value);    
}

bool ArmClient::setFrontCyclerAmp2(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler amp2 > " << std::to_string(value));     
    return pCyclicChannelClient->sendMessage(CyclicTalker::eCYCLIC_FRONT2_AMP, value);    
}

bool ArmClient::setFrontCyclerAngle2(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler angle2 > " << std::to_string(value));     
    return pCyclicChannelClient->sendMessage(CyclicTalker::eCYCLIC_FRONT2_ANGLE, value);    
}

bool ArmClient::setFrontCyclerFreq2(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler freq2 > " << std::to_string(value));     
    return pCyclicChannelClient->sendMessage(CyclicTalker::eCYCLIC_FRONT2_FREQ, value);    
}

bool ArmClient::setFrontCyclerPhase2(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler phase2 > " << std::to_string(value));     
    return pCyclicChannelClient->sendMessage(CyclicTalker::eCYCLIC_FRONT2_PHASE, value);    
}

bool ArmClient::setFrontCyclerAction(int value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: front cycler action > " << std::to_string(value));     
    return pCyclicChannelClient->sendMessage(CyclicTalker::eCYCLIC_FRONT_ACTION, (float)value);        
}

// EXTRA TOPIC ...

bool ArmClient::fullStop()
{
    LOG4CXX_DEBUG(logger, "ArmClient: full stop > ");     
    return pExtraChannelClient->sendMessage(BasicTalker::eBASIC_FULL_STOP, 0.0);        
}

bool ArmClient::endNode()
{
    LOG4CXX_DEBUG(logger, "ArmClient: end arm > ");     
    return pExtraChannelClient->sendMessage(BasicTalker::eBASIC_CONTROL_END, 0.0);        
}
}