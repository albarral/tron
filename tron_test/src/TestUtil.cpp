/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "TestUtil.h"
#include "tron/util/Code.h"
#include "tron/util/CodeInterpreter.h"
#include "tron/util/MessageQueue.h"
#include "tron/util/Try.h"
#include "tron/util/groups/Element.h"
#include "tron/util/groups/Group.h"
#include "tron/util/groups/SuperGroup.h"

using namespace log4cxx;

LoggerPtr TestUtil::logger(Logger::getLogger("tron"));

// Constructor 
TestUtil::TestUtil()
{    
    modName = "TestUtil";
 }

void TestUtil::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    //testMessageQueue();        
    //testGroups();
    //testCodeInterpreter();
    testTry();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestUtil::testMessageQueue()
{
    LOG4CXX_INFO(logger, modName + ": testMessageQueue ...");

    std::string msg;
    tron::MessageQueue oMessageQueue;
        
    msg = "message1";
    oMessageQueue.add(msg);
    msg = "message2";
    oMessageQueue.add(msg);
    
    LOG4CXX_INFO(logger, "message queue has messages " + std::to_string(oMessageQueue.getSize()));
    
    while (oMessageQueue.isFilled())
    {
        msg = oMessageQueue.fetch();
        
        LOG4CXX_INFO(logger, "message fetched: " + msg);
    }        
}

void TestUtil::testGroups()
{
    LOG4CXX_INFO(logger, modName + ": testGroups ...");

    tron::SuperGroup oSuperGroup(10, "supergroup10");
    tron::Group oGroup1(1, "group1");
    tron::Group oGroup2(2, "group2");
    tron::Element oElement1(1, "elem1");
    tron::Element oElement2(2, "elem2");
    tron::Element oElement3(3, "elem3");
        
    oGroup1.addElement(oElement1);
    oGroup1.addElement(oElement2);
    oGroup1.addElement(oElement3);    

    oGroup2.addElement(oElement1);
    oGroup2.addElement(oElement2);
    oGroup2.addElement(oElement3);    
    
    oSuperGroup.addGroup(oGroup1);
    oSuperGroup.addGroup(oGroup2);
    
    LOG4CXX_INFO(logger, oSuperGroup.toString());        
}

void TestUtil::testCodeInterpreter()
{
    LOG4CXX_INFO(logger, modName + ": testInterpreter ...");

    tron::Code oCode1(7, "seven");
    tron::Code oCode2(8, "eight");
    tron::Code oCode3(9, "nine");
    
    std::vector<tron::Code> listCodes; 
    listCodes.push_back(oCode1);
    listCodes.push_back(oCode2);
    listCodes.push_back(oCode3);
    
    tron::CodeInterpreter oCodeInterpreter;
    oCodeInterpreter.addKnowledge(listCodes);
    
    LOG4CXX_INFO(logger, oCodeInterpreter.describeKnowledge());   
    
    std::string word = "nine";
    int codeId = oCodeInterpreter.interpretCode(word);
    LOG4CXX_INFO(logger, "word interpretation: " + word + " = " + std::to_string(codeId));   

    int number = 7;
    std::string codeName = oCodeInterpreter.writeCode(number);
    LOG4CXX_INFO(logger, "code writing : " + std::to_string(number) + " = " + codeName);   
}

void TestUtil::testTry()
{
    LOG4CXX_INFO(logger, modName + ": testTry ...");

    tron::Try oTry;
    
    oTry.update(true);
    oTry.update(true);
    oTry.update(true);
    oTry.update(false);
        
    LOG4CXX_INFO(logger, "usage = " + std::to_string(oTry.getUsage()));        
    LOG4CXX_INFO(logger, "success rate = " + std::to_string(100.0*oTry.getSuccessRate()));        
}
