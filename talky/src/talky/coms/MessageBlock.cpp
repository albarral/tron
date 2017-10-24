/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <deque>

#include "talky/coms/MessageBlock.h"
#include "talky/coms/StringUtil.h"
#include "talky/Topics.h"

namespace talky
{
MessageBlock::MessageBlock()
{
    rawText = "";
    reset();
}

void MessageBlock::reset()
{
    listMessages.clear();    
}

void MessageBlock::addMessage(Message& oMessage)
{
     listMessages.push_back(oMessage);
}

void MessageBlock::composeBlock()
{
    rawText = Topics::BLOCK_HEADER;
    for (Message& oMessage : listMessages)
    {
        rawText += Topics::MSG_SEPARATOR + oMessage.getRawText();
    }
}

void MessageBlock::digestBlock()
{
    // first we reset the message block
    reset();
        
    // split raw text in tokens 
    std::deque<std::string> listTokens = StringUtil::split2(rawText, Topics::MSG_SEPARATOR); 
    int numTokens = listTokens.size();

    // eliminate header from tokens list
    if (numTokens > 0)
        listTokens.pop_front();        
        
    if (numTokens > 1)
    {
        // for each simple raw text 
        for (std::string text : listTokens)
        {
            // create simple message (just raw text) and add it to list
            Message oMessage;
            oMessage.setRawText(text);
            addMessage(oMessage);
        }
    }
}

bool MessageBlock::isInterpreted()
{
    // block not interpreted if no forming messages
    if (listMessages.empty())
        return false;

    // get number of intepreted messages
    int numMessagesInterpreted = 0;
    for (Message& oMessage : listMessages)
    {
        if (oMessage.isInterpreted())
            numMessagesInterpreted++;
    }
    
    // block is considered interpreted if all its messages have been interpreted
    return (numMessagesInterpreted == listMessages.size());
}


std::string MessageBlock::toString()
{
    std::string desc = "[MessageBlock]\n";

    for (Message& oMessage : listMessages)
    {
        desc += oMessage.toString() + "\n";
    }
    
    return desc;
}    

}