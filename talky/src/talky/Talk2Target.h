#ifndef __TALKY_TALK2TARGET_H
#define __TALKY_TALK2TARGET_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <deque>
#include <mutex>
#include <string>
#include <log4cxx/logger.h>

#include "talky/coms/Command.h"
#include "talky/talk/Interpreter.h"

namespace talky
{
// Generic class used to manage commands for a specific topic category.
// Commands are converted to messages by an interpreter.
// Commands are processed on demand in fifo order. 
// Thread safety implemented.
class Talk2Target
{    
private:
    static log4cxx::LoggerPtr logger;      
    std::mutex mutex;
    bool benabled;                          // flag indicating the object is initialized
    int topic;
    int category;
    Interpreter oInterpreter;     // commands interpreter and message builder
    std::deque<talky::Command> listCommands;    // list of requested commands
    std::string message;               // raw message obtained from last processed command
        
public:
    Talk2Target();
    ~Talk2Target();
    
    bool isEnabled() {return benabled;};   
    void init(int topic, int category);

    // add full command to pending list
    void addCommand(int concept, float quantity);   
    // add short command (no quantity) to pending list
    void addCommand(int concept);   
    // checks if there are pending commands to process
    bool isArmed(); 
    // converts first pending command into message (the older in list)
    bool processCommand();    
    // gets last converted message 
    std::string getRawMessage() {return message;};
};
}
#endif
