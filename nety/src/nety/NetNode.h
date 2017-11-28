#ifndef __NETY_NETNODE_H
#define __NETY_NETNODE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "talky/coms/Command.h"
#include "talky/coms/CommandQueue.h"
#include "talky/talk/Interpreter.h"
#include "tuly/utils/MessageQueue.h"

namespace nety
{
// Base class used for robotic network nodes.
// Node types: input node (works as info receptor) and output node (works as info transmitter).
// Node elements: 
// - messages queue (transmitted info)
// - commands queue (interpreted info)
// - talky interpreter (to interpret info and build messages)   
// Node requisites to work: 
// - must be tuned to a talky topic-category
// - must be connected to a comy link (client, server, publisher o subscriber)
class NetNode
{    
protected:
    static log4cxx::LoggerPtr logger;      
    bool btypeOut;           // node type (true means output node, false means input node)
    int topic;
    int category;
    bool btuned;              // node tuned to a topic-category
    bool bconnected;       // node connected to a comy link
    talky::CommandQueue oCommandQueue;  // commands queue 
    tuly::MessageQueue oMessageQueue;       // messages queue 
    talky::Interpreter oInterpreter;     // interpreter and message builder
        
public:
    NetNode();
    ~NetNode();

    bool isTuned() {return btuned;};
    bool isConnected() {return bconnected;};

    // tune node to given topic-category
    void init(int topic, int category);   

    bool hasCommands();
    bool hasMessages();
    int getSizeCommandsQueue();
    int getSizeMessagesQueue();

    // add command to commands queue with predefined topic-category (OUTPUT NODE)
    void addCommand(int concept, float quantity);   
    // add command to commands queue with predefined topic-category (OUTPUT NODE)
    void addCommand(int concept);   
    // fetch command from commands queue removing it (INPUT NODE)
    bool fetchCommand(talky::Command& oCommand);

    // clean queues
    void clean();
    
    // process queues (commands queue for output nodes, and messages queue for input nodes)
    bool process();
    // sends info out to network (OUTPUT NODE)
    virtual bool flush() = 0;
    // absorb info from network (INPUT NODE)
    virtual bool absorb() = 0;

protected:  
    // connect node to proper link
    virtual void connect() = 0;
    
private:  
    // OUTPUT NODE: transforms commands to messages (cleaning commands queue)
    bool processCommandsQueue();
    // INPUT NODE: transforms messages to commands (cleaning messages queue)
    bool processMessagesQueue();    
    
};

}
#endif
