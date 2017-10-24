/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h> // for sleep() 

#include "Listener.h"
#include "talky/Topics.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr Listener::logger(Logger::getLogger("tron"));

// Constructor 
Listener::Listener()
{    
    modName = "Listener";
    // prepare interpreter for arm topic communications
    oInterpreter.addLanguage(talky::Topics::eTOPIC_ARM);
    // prepare coms subscriber
    oComySubscriber.connect();    
    // reset joints info
    oJointAngles0.reset();    
 }

void Listener::run(int numIterations)
{
    LOG4CXX_INFO(logger, modName + ": running listener for iterations " + std::to_string(numIterations));
    
    int counter = 0;
    int period = 100000;    // 100 ms
    while (counter < numIterations)
    {
        listen();
        counter++;
        
        usleep(period);
    }            

    LOG4CXX_INFO(logger, modName + ": listener finished\n");
}

void Listener::listen()
{
    // prepare coms subscriber
    if (!oComySubscriber.isConnected())
    {                
        LOG4CXX_ERROR(logger, modName + ": coms subscriber not connected. Exit!");                        
        return;
    }
    
    bool bnewInfo;
    
    if (oComySubscriber.readMessage())
    {            
        bnewInfo = processMessage(oComySubscriber.getRawMessage());            
    }            
    else
        bnewInfo = false;       

    // if new info received and different from previous one
    if (bnewInfo && !oJointAngles.isEqual(oJointAngles0))
    {                        
        LOG4CXX_INFO(logger, modName + ": " + oJointAngles.toString());
                
        // store data for next iteration
        oJointAngles0 = oJointAngles;
    }   
}

bool Listener::processMessage(std::string rawMessage)
{
    bool bret = false;

    // interpret received message
    if (oInterpreter.processMessage(rawMessage))
    {
        // if message block
        if (oInterpreter.isBlockProcessed())
        {
            // show obtained command block
            LOG4CXX_INFO(logger, modName + ": msg block processed ok");        
            LOG4CXX_INFO(logger, modName + ": " + oInterpreter.getCommandBlock().toString());        

            // process interpreted command block
            bret = oJointAngles.readJointPositions(oInterpreter.getCommandBlock());
        }
        // if simple message
        else
        {
            LOG4CXX_WARN(logger, modName + ": simple msg received, ignore");
        }            
    }
    else
    {               
        LOG4CXX_WARN(logger, modName + ": msg processing failed! - " + rawMessage);            
    }

    return bret;    
}

}