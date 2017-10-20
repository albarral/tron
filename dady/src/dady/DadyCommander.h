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

public:
    DadyCommander();
    //~DadyCommander();
    
    bool checkValidCommand(std::string entry);

    void showAvailableCommands();
};
}		
#endif
