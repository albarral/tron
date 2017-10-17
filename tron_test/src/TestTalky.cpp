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

    testMessageInterpretation(oInterpreter);        
    testCommandInterpretation1(oInterpreter);        
    testCommandInterpretation2(oInterpreter);        
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTalky::testMessageInterpretation(talky::Interpreter& oInterpreter)
{
    LOG4CXX_INFO(logger, modName + ": testMessageInterpretation ...");

    // test message
    std::string sep = talky::Topics::FIELD_SEPARATOR;
    std::string sep2 = talky::Topics::MSG_SEPARATOR;
    std::string msg1 = "arm" + sep + "axis" + sep + "tilt" + sep + "10.0";            
    std::string msg2 = "arm" + sep + "cyclic" + sep + "move";
    std::string msg = talky::Topics::BLOCK_HEADER + sep2 + msg1 + sep2 + msg2;
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

void TestTalky::testCommandInterpretation1(talky::Interpreter& oInterpreter)
{
    LOG4CXX_INFO(logger, modName + ": testCommandInterpretation 1 ...");

    talky::Command oCommand;
    oCommand.setTopic(talky::Topics::eTOPIC_ARM);
    oCommand.setCategory(talky::ArmTopic::eCAT_ARM_JOINT);
    oCommand.setConcept(talky::ArmTopic::eJOINT_HS_POS);
    oCommand.setQuantity(10);
    LOG4CXX_INFO(logger, modName + ": command1 > " + oCommand.toString());
    
    talky::Message oMessage;
    if (oInterpreter.buildSimpleMessage(oCommand, oMessage))
    {
        // show obtained command
        LOG4CXX_INFO(logger, modName + ": command processed ok");        
        LOG4CXX_INFO(logger, modName + ": " + oMessage.toString());                
    }
    else
    {
        LOG4CXX_WARN(logger, modName + ": command processing failed!");            
        LOG4CXX_WARN(logger, modName + ": " + oCommand.toStringValidity());                    
    }
    
}

void TestTalky::testCommandInterpretation2(talky::Interpreter& oInterpreter)
{
    LOG4CXX_INFO(logger, modName + ": testCommandInterpretation 2 ...");

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
    }
    else
    {
        LOG4CXX_WARN(logger, modName + ": command processing failed!");    
        for (talky::Command& oCommand : oCommandBlock.getListCommands())
            LOG4CXX_WARN(logger, modName + ": " + oCommand.toStringValidity());                    
    }
    
}