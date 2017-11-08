/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "dady/DadyCommunicator.h"
#include "talky/Topics.h"
#include "talky/languages/ArmLanguage.h"
#include "talky/topics/ArmTopic.h"

using namespace log4cxx;

namespace dady
{
LoggerPtr DadyCommunicator::logger(Logger::getLogger("dady"));

// Constructor 
DadyCommunicator::DadyCommunicator()
{    
 }

bool DadyCommunicator::connect2Amy()
{
    talky::ArmLanguage oArmLanguage;
    // prepare communication clients
    oComyClientJoints.connect(talky::Topics::ARM_TOPIC, oArmLanguage.CAT_ARM_JOINT);
    oComyClientAxis.connect(talky::Topics::ARM_TOPIC, oArmLanguage.CAT_ARM_AXIS);
    oComyClientCyclic.connect(talky::Topics::ARM_TOPIC, oArmLanguage.CAT_ARM_CYCLIC);
    oComyClientExtra.connect(talky::Topics::ARM_TOPIC, oArmLanguage.CAT_ARM_EXTRA);    
    
    if (oComyClientJoints.isConnected() && 
            oComyClientAxis.isConnected() &&
            oComyClientCyclic.isConnected() &&
            oComyClientExtra.isConnected())
    {
        return true;
    }
    else
    {
        LOG4CXX_ERROR(logger, "DadyCommunicator: failed initialization, coms clients not connected!");                        
        return false;
    }    
}

// send command to amy process
bool DadyCommunicator::sendCommand(std::string message, int topic, int category)
{
    if (topic != talky::Topics::eTOPIC_ARM)
    {
        LOG4CXX_WARN(logger, "DadyCommunicator: not an arm topic command, send ignored!");                        
        return false;
    }
    
    bool bsent;
    switch (category)
    {
        case talky::ArmTopic::eCAT_ARM_JOINT:
            bsent = sendCommand2Channel(oComyClientJoints, message);
            break;

        case talky::ArmTopic::eCAT_ARM_AXIS:
            bsent = sendCommand2Channel(oComyClientAxis, message);
            break;
        
        case talky::ArmTopic::eCAT_ARM_CYCLIC:
            bsent = sendCommand2Channel(oComyClientCyclic, message);
            break;

        case talky::ArmTopic::eCAT_ARM_EXTRA:
            bsent = sendCommand2Channel(oComyClientExtra, message);
            break;

        default:
            bsent = false;
            break;
    }
    
    if (!bsent)
    {
        LOG4CXX_WARN(logger, "DadyCommunicator: message not sent");                        
    }

    return bsent;
}

// send command to amy process
bool DadyCommunicator::sendCommand2Channel(comy::ComyFileClient& oComyClient, std::string message)
{
    if (!oComyClient.isConnected())
    {
        LOG4CXX_ERROR(logger, "DadyCommunicator: client not connected!");                        
        return false;
    }    

    // send message 
    bool bsent = oComyClient.sendMessage(message);
    
    if (!bsent)
    {
        LOG4CXX_WARN(logger, "DadyCommunicator: message not sent");                        
    }

    return bsent;
}

}