/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "TestUtil.h"
#include "tron/util/MessageQueue.h"
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
    testGroups();
        
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
    tron::Element oElement1(1, "elem1", 4);
    tron::Element oElement2(2, "elem2", 3);
    tron::Element oElement3(3, "elem3", 5);
        
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


