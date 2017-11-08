#ifndef __AMY_CONSOLE_DADYCOMMANDER_H
#define __AMY_CONSOLE_DADYCOMMANDER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

#include "talky/talk/Interpreter.h"

namespace dady
{
// Class used to interpret user entered commands in talky communication language.
class DadyCommander 
{
private:
    static log4cxx::LoggerPtr logger;    
    talky::Interpreter oInterpreter;        // interpreter for talky communications
    int msgTopic;                               // topic of interpreted message
    int msgCategory;                          // category of interpreted message

public:
    DadyCommander();
    //~DadyCommander();
    
    bool checkValidCommand(std::string entry);
    int getInterpretedTopic() {return msgTopic;};
    int getInterpretedCategory() {return msgCategory;};

    void showAvailableCommands();
};
}		
#endif
