#ifndef __TALKY_MESSAGE_BLOCK_H
#define __TALKY_MESSAGE_BLOCK_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "talky/coms/Message.h"

namespace talky
{
/** 
 * Class used to represent a communications message block (a big message composed of multiple message). 
 */
class MessageBlock 
{
private:    
    std::string rawText;                 /*! raw text of message */
    std::vector<Message> listMessages;       /*! collection of messages that form the block */
        
public:
    MessageBlock();    
    
    void reset();
    
    void setRawText(std::string text) {rawText = text;};
    void addMessage(Message& oMessage);

    std::string getRawText() {return rawText;};
    std::vector<Message>& getListMessages() {return listMessages;};
       
    // build the block's raw text from all composing messages
    void composeBlock();
    // extract all composing messages from the block's raw text
    void digestBlock();

    // check if block was fully interpreted
    bool isInterpreted();
    
    std::string toString();
};
}
#endif
