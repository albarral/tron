/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "TestTalky2.h"
#include "tron/talky2/clients/ArmClient.h"

using namespace log4cxx;

LoggerPtr TestTalky2::logger(Logger::getLogger("tron"));

// Constructor 
TestTalky2::TestTalky2()
{    
    modName = "TestTalky2";
 }

void TestTalky2::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    tron::ArmClient oArmClient;

    testWriteMessage(oArmClient, 12.0);        
    testWriteMessage(oArmClient, 22.0);        
    testWriteMessage(oArmClient, 13.0);        
//    testReadMessage(oInterpreter, msg);        
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

//void TestTalky2::testReadMessage(talky::Interpreter& oInterpreter, std::string msg)
//{
//    LOG4CXX_INFO(logger, modName + ": testReadMessage ...");
//    LOG4CXX_INFO(logger, modName + ": msg > " + msg);
//
//    // interpret test message
//    if (oInterpreter.processMessage(msg))
//    {
//        // if simple message
//        if (!oInterpreter.isBlockProcessed())
//        {
//            // show obtained command
//            LOG4CXX_INFO(logger, modName + ": msg processed ok");        
//            LOG4CXX_INFO(logger, modName + ": " + oInterpreter.getCommand().toString());        
//        }
//        // if message block
//        else
//        {
//            // show obtained command block
//            LOG4CXX_INFO(logger, modName + ": msg block processed ok");        
//            LOG4CXX_INFO(logger, modName + ": " + oInterpreter.getCommandBlock().toString());        
//        }            
//    }
//    else
//    {
//        LOG4CXX_WARN(logger, modName + ": msg processing failed!");            
//    }
//}

void TestTalky2::testWriteMessage(tron::ArmClient& oArmClient, float hs)
{
    LOG4CXX_DEBUG(logger, modName + ": testWriteMessage ...");

    if (oArmClient.setHS(hs))
    {
        LOG4CXX_INFO(logger, modName + ": sent HS > " << std::to_string(hs));
    }
    else
    {
        LOG4CXX_ERROR(logger, modName + ": sent HS failed");
    }        
}


