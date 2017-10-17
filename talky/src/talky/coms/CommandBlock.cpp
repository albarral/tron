/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/coms/CommandBlock.h"

namespace talky
{
CommandBlock::CommandBlock()
{
    reset();
}

void CommandBlock::reset()
{
    listCommands.clear();
}

void CommandBlock::addCommand(Command& oCommand)
{
    listCommands.push_back(oCommand);
}    

bool CommandBlock::isInterpreted()
{
    // block not interpreted if no forming messages
    if (listCommands.empty())
        return false;

    // get number of intepreted messages
    int numCommandsInterpreted = 0;
    for (Command& oCommand : listCommands)
    {
        if (oCommand.isInterpreted())
            numCommandsInterpreted++;
    }
    
    // block is considered interpreted if all its commands have been interpreted
    return (numCommandsInterpreted == listCommands.size());
}

std::string CommandBlock::toString()
{
    std::string desc = "[CommandBlock]\n";

    for (Command& oCommand : listCommands)
    {
        desc += oCommand.toString() + "\n";
    }
    return desc;
}    

}
