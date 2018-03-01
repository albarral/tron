/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/arm/ArmClient.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/ArmTopics.h"

using namespace log4cxx;

namespace tron
{
ArmClient::ArmClient()
{    
}

//ArmClient::~ArmClient()
//{    
//}

// JOINT TOPIC ...

bool ArmClient::setHS(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set HS > " << std::to_string(value));
    return sendJointCommand(JointTalker::eJOINT_HS_POS, value);
}

bool ArmClient::setVS(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set VS > " << std::to_string(value));
    return sendJointCommand(JointTalker::eJOINT_VS_POS, value);
}

bool ArmClient::setELB(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set ELB > " << std::to_string(value));
    return sendJointCommand(JointTalker::eJOINT_ELB_POS, value);
}

bool ArmClient::setHWRI(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set HWRI > " << std::to_string(value));
    return sendJointCommand(JointTalker::eJOINT_HWRI_POS, value);
}

bool ArmClient::setVWRI(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set VWRI > " << std::to_string(value));
    return sendJointCommand(JointTalker::eJOINT_VWRI_POS, value);
}

// AXIS TOPIC ...

bool ArmClient::setPan(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set pan > " << std::to_string(value));
     return sendAxisCommand(AxisTalker::eAXIS_PAN_POS, value);
}

bool ArmClient::setTilt(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set tilt > " << std::to_string(value));
     return sendAxisCommand(AxisTalker::eAXIS_TILT_POS, value);
}

bool ArmClient::setRadial(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set radius > " << std::to_string(value));
     return sendAxisCommand(AxisTalker::eAXIS_RAD_POS, value);
}

bool ArmClient::setPanSpeed(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set pan speed > " << std::to_string(value));
     return sendAxisCommand(AxisTalker::eAXIS_PAN_SPEED, value);
}

bool ArmClient::setTiltSpeed(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set tilt speed > " << std::to_string(value));
     return sendAxisCommand(AxisTalker::eAXIS_TILT_SPEED, value);
}

bool ArmClient::setRadialSpeed(float value)
{    
    LOG4CXX_DEBUG(logger, "ArmClient: set radial speed > " << std::to_string(value));
     return sendAxisCommand(AxisTalker::eAXIS_RAD_SPEED, value);
}

// CYCLIC TOPIC ...

bool ArmClient::setFrontCyclerAmp1(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler amp1 > " << std::to_string(value));     
    return sendCyclicCommand(CyclicTalker::eCYCLIC_FRONT1_AMP, value);    
}

bool ArmClient::setFrontCyclerAngle1(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler angle1 > " << std::to_string(value));     
    return sendCyclicCommand(CyclicTalker::eCYCLIC_FRONT1_ANGLE, value);    
}

bool ArmClient::setFrontCyclerFreq1(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler freq1 > " << std::to_string(value));     
    return sendCyclicCommand(CyclicTalker::eCYCLIC_FRONT1_FREQ, value);    
}

bool ArmClient::setFrontCyclerAmp2(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler amp2 > " << std::to_string(value));     
    return sendCyclicCommand(CyclicTalker::eCYCLIC_FRONT2_AMP, value);    
}

bool ArmClient::setFrontCyclerAngle2(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler angle2 > " << std::to_string(value));     
    return sendCyclicCommand(CyclicTalker::eCYCLIC_FRONT2_ANGLE, value);    
}

bool ArmClient::setFrontCyclerFreq2(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler freq2 > " << std::to_string(value));     
    return sendCyclicCommand(CyclicTalker::eCYCLIC_FRONT2_FREQ, value);    
}

bool ArmClient::setFrontCyclerPhase(float value)
{
    LOG4CXX_DEBUG(logger, "ArmClient: set front cycler phase > " << std::to_string(value));     
    return sendCyclicCommand(CyclicTalker::eCYCLIC_FRONT_PHASE, value);    
}

// EXTRA TOPIC ...

bool ArmClient::stopArm()
{
    LOG4CXX_DEBUG(logger, "ArmClient: stop arm > ");     
    return sendExtraCommand(BasicTalker::eEXTRA_ARM_STOP, 0.0);        
}

bool ArmClient::keepTilt()
{
    LOG4CXX_DEBUG(logger, "ArmClient: keep tilt > ");     
    return sendExtraCommand(BasicTalker::eEXTRA_KEEP_TILT, 0.0);        
}

bool ArmClient::endArm()
{
    LOG4CXX_DEBUG(logger, "ArmClient: end arm > ");     
    return sendExtraCommand(BasicTalker::eEXTRA_ARM_END, 0.0);        
}

// MESSAGE BUILDING & SENDING ...

bool ArmClient::sendJointCommand(int code, float value)
{    
    if (oJointTalker.buildMessage(code, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopics::eARM_JOINT, message);
    }
    else
        return false;
}

bool ArmClient::sendAxisCommand(int code, float value)
{    
    if (oAxisTalker.buildMessage(code, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopics::eARM_AXIS, message);
    }
    else
        return false;
}

bool ArmClient::sendCyclicCommand(int code, float value)
{    
    if (oCyclicTalker.buildMessage(code, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopics::eARM_CYCLIC, message);
    }
    else
        return false;
}

bool ArmClient::sendExtraCommand(int code, float value)
{    
    if (oBasicTalker.buildMessage(code, value, message))
    {
        return oWire.sendMsg(RobotNodes::eNODE_ARM, ArmTopics::eARM_EXTRA, message);
    }
    else
        return false;
}

}