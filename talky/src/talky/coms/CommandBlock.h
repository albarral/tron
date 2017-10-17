#ifndef __TALKY_COMMAND_BLOCK_H
#define __TALKY_COMMAND_BLOCK_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "talky/coms/Command.h"

namespace talky
{
/** 
 * Class used to represent a communications command.
 */
class CommandBlock
{
private:    
    std::vector<Command> listCommands;       /*! collection of commands that form the block */
        
public:
    CommandBlock();        
    
    void reset();    
    
    void addCommand(Command& oCommand);
    std::vector<Command>& getListCommands() {return listCommands;};
    
    // check if block was fully interpreted
    bool isInterpreted();

    std::string toString();    
};
}
#endif
