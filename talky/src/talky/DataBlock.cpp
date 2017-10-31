/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/DataBlock.h"
#include "talky/coms/Command.h"

namespace talky
{
void DataBlock::reset()
{
    topic = -1;
    category = -1;
    blockName = "";
    listElements.clear();
}

void DataBlock::addElement(int value)
{            
    listElements.push_back(value);
}

bool DataBlock::checkCompatibleBlock(CommandBlock& oCommandBlock)
{
    // if number of elements & commands differ, not compatible
    if (listElements.size() != oCommandBlock.getListCommands().size())
        return false;

    bool bcompatible = true;
    int i = 0;
    for (talky::Command& oCommand : oCommandBlock.getListCommands())
    {
        // if not expected topic, category and element, not compatible
        if (oCommand.getTopic() != topic || 
                oCommand.getCategory() != category || 
                oCommand.getConcept() != listElements.at(i))
        {
            bcompatible = false;
            break;            
        }
        else
            i++;
    }
    
    return bcompatible;    
}

std::string DataBlock::toString()
{
    std::string desc = "[DataBlock]: topic = " + std::to_string(topic) + 
                             ", category = " + std::to_string(category) +
                             ", blockName = " + blockName +
                             ", elements = ";
    for (int element : listElements)
    {
        desc += element + " ";
    }
    
    return desc;
}

}
