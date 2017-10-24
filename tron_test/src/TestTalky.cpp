/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "TestTalky.h"
#include "talky/Topics.h"
#include "talky/coms/Command.h"
#include "talky/coms/CommandBlock.h"
#include "talky/coms/Message.h"
#include "talky/coms/MessageBlock.h"
#include "talky/topics/ArmTopic.h"
#include "talky2/arm/ArmJointAngles.h"

using namespace log4cxx;

LoggerPtr TestTalky::logger(Logger::getLogger("tron"));

// Constructor 
TestTalky::TestTalky()
{    
    modName = "TestTalky";
 }

void TestTalky::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    // create interpreter
    talky::Interpreter oInterpreter;
    // and prepare it for arm topic communications
    oInterpreter.addLanguage(talky::Topics::eTOPIC_ARM);
    // show known languages
    //oInterpreter.showKnowledge();

    std::string msg;
//    LOG4CXX_INFO(logger, "\n");
//    msg = testWriteMessage(oInterpreter);        
//    testReadMessage(oInterpreter, msg);        

    LOG4CXX_INFO(logger, "\n");
    msg = testWriteMessageBlock(oInterpreter);        
    testReadMessage(oInterpreter, msg);        

//    LOG4CXX_INFO(logger, "\n");
//    msg = testWriteMessageArmAngles(oInterpreter);
//    testReadMessage(oInterpreter, msg);        
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTalky::testReadMessage(talky::Interpreter& oInterpreter, std::string msg)
{
    LOG4CXX_INFO(logger, modName + ": testReadMessage ...");
    LOG4CXX_INFO(logger, modName + ": msg > " + msg);

    // interpret test message
    if (oInterpreter.processMessage(msg))
    {
        // if simple message
        if (!oInterpreter.isBlockProcessed())
        {
            // show obtained command
            LOG4CXX_INFO(logger, modName + ": msg processed ok");        
            LOG4CXX_INFO(logger, modName + ": " + oInterpreter.getCommand().toString());        
        }
        // if message block
        else
        {
            // show obtained command block
            LOG4CXX_INFO(logger, modName + ": msg block processed ok");        
            LOG4CXX_INFO(logger, modName + ": " + oInterpreter.getCommandBlock().toString());        
        }            
    }
    else
    {
        LOG4CXX_WARN(logger, modName + ": msg processing failed!");            
    }
}

std::string TestTalky::testWriteMessage(talky::Interpreter& oInterpreter)
{
    LOG4CXX_INFO(logger, modName + ": testWriteMessage ...");

    std::string rawMessage = "";

    talky::Command oCommand;
    oCommand.setTopic(talky::Topics::eTOPIC_ARM);
    oCommand.setCategory(talky::ArmTopic::eCAT_ARM_JOINT);
    oCommand.setConcept(talky::ArmTopic::eJOINT_HS_POS);
    oCommand.setQuantity(10);
    LOG4CXX_INFO(logger, modName + ": command > " + oCommand.toString());
    
    talky::Message oMessage;
    if (oInterpreter.buildSimpleMessage(oCommand, oMessage))
    {
        // show obtained command
        LOG4CXX_INFO(logger, modName + ": command processed ok");        
        LOG4CXX_INFO(logger, modName + ": " + oMessage.toString());        

        rawMessage = oMessage.getRawText();        
    }
    else
    {
        LOG4CXX_WARN(logger, modName + ": command processing failed!");            
        LOG4CXX_WARN(logger, modName + ": " + oCommand.toStringValidity());                    
    }
    
    return rawMessage;    
}

std::string TestTalky::testWriteMessageBlock(talky::Interpreter& oInterpreter)
{
    LOG4CXX_INFO(logger, modName + ": testWriteMessageBlock ...");

    std::string rawMessage = "";
    
    talky::Command oCommand1;
    oCommand1.setTopic(talky::Topics::eTOPIC_ARM);
    oCommand1.setCategory(talky::ArmTopic::eCAT_ARM_JOINT);
    oCommand1.setConcept(talky::ArmTopic::eJOINT_HS_POS);
    oCommand1.setQuantity(10);
    talky::Command oCommand2;
    oCommand2.setTopic(talky::Topics::eTOPIC_ARM);
    oCommand2.setCategory(talky::ArmTopic::eCAT_ARM_JOINT);
    oCommand2.setConcept(talky::ArmTopic::eJOINT_VS_POS);
    oCommand2.setQuantity(15);
    
    talky::CommandBlock oCommandBlock;
    oCommandBlock.addCommand(oCommand1);
    oCommandBlock.addCommand(oCommand2);
    LOG4CXX_INFO(logger, modName + ": commandBlock > " + oCommandBlock.toString());
    
    talky::MessageBlock oMessageBlock;
    if (oInterpreter.buildMessageBlock(oCommandBlock, oMessageBlock))
    {
        // show obtained command
        LOG4CXX_INFO(logger, modName + ": command block processed ok");        
        LOG4CXX_INFO(logger, modName + ": " + oMessageBlock.toString());                
        LOG4CXX_INFO(logger, modName + ": " + oMessageBlock.getRawText());
        rawMessage = oMessageBlock.getRawText();
    }
    else
    {
        LOG4CXX_WARN(logger, modName + ": command processing failed!");    
        for (talky::Command& oCommand : oCommandBlock.getListCommands())
            LOG4CXX_WARN(logger, modName + ": " + oCommand.toStringValidity());   
    }

    return rawMessage;    
}

std::string TestTalky::testWriteMessageArmAngles(talky::Interpreter& oInterpreter)
{
    LOG4CXX_INFO(logger, modName + ": testWriteMessageArmAngles ...");

    std::string rawMessage = "";

    talky2::ArmJointAngles oArmJointAngles;     // talky2 object for arm position info
    
    oArmJointAngles.setPosHS(10.0);
    oArmJointAngles.setPosVS(11.0);
    oArmJointAngles.setPosEL(12.0);
    oArmJointAngles.setPosHW(13.0);
    oArmJointAngles.setPosVW(14.0);
    
    talky::CommandBlock oCommandBlock;
    oArmJointAngles.writeJointPositions(oCommandBlock);
    LOG4CXX_INFO(logger, modName + ": commandBlock > " + oCommandBlock.toString());
    
    talky::MessageBlock oMessageBlock;
    if (oInterpreter.buildMessageBlock(oCommandBlock, oMessageBlock))
    {
        // show obtained command
        LOG4CXX_INFO(logger, modName + ": command block processed ok");        
        LOG4CXX_INFO(logger, modName + ": " + oMessageBlock.toString());                
        LOG4CXX_INFO(logger, modName + ": " + oMessageBlock.getRawText());                
        rawMessage = oMessageBlock.getRawText();
    }
    else
    {
        LOG4CXX_WARN(logger, modName + ": command processing failed!");    
        for (talky::Command& oCommand : oCommandBlock.getListCommands())
            LOG4CXX_WARN(logger, modName + ": " + oCommand.toStringValidity());                    
    }
    
    return rawMessage;        
}