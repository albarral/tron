#ifndef __TALKY_INTERPRETER_H
#define __TALKY_INTERPRETER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include <map>
#include <string>

#include "talky/talk/Talker.h"
#include "talky/coms/Command.h"
#include "talky/coms/CommandBlock.h"
#include "talky/coms/Message.h"
#include "talky/coms/MessageBlock.h"

namespace talky
{
/** 
 * Class used to interpret and speak communication messages. 
 * It uses talkers, one for each different topic.
 */
class Interpreter
{    
private:
    static log4cxx::LoggerPtr logger;
    std::map<std::string, int> mapTopicNumbers;   /*! map of topic numbers <topic_name, topicId>*/    
    std::map<int, std::string> mapTopicNames;      /*! map of topic names <topicId, topic_name>*/    
    std::map<int, Talker> mapTalkers;                   /*! map of topic talkers <topicId, topic Talker>*/    
    bool blockProcessing;                                       /*! flag indicating a message block has been processed */
    // simple processing
    Command oCommand;                                    /*! interpreted command */   
    // block processing
    CommandBlock oCommandBlock;                     /*! interpreted command block */   
    
public:
    Interpreter();              	
    ~Interpreter();

    void reset();    

    // adds language capability for the given topic
    void addLanguage(int topicId);
    
    // interprets given message/message block converting it to a simple command/command block
    // returns true if processed ok
    bool processMessage(std::string text);    
    
    // converts given command in a communication message
    // returns true if conversion was ok
    bool buildSimpleMessage(Command& oCommand, Message& oMessage); 
    
    // converts given command block in a communication message block
    // returns true if conversion was ok
    bool buildMessageBlock(CommandBlock& oCommandBlock, MessageBlock& oMessageBlock);

    // returns block processed flag
    bool isBlockProcessed() {return blockProcessing;};
    // gets interpreted command
    Command& getCommand() {return oCommand;};
    // gets composed message
    CommandBlock& getCommandBlock() {return oCommandBlock;};
    
    // checks if given topic is understood by this interpreter
    bool understandsLanguage(std::string topicName);    
    
    // show all languages known by the interpreter
    void showKnowledge();
    
private: 
    // interprets given message converting it to a simple command
    // returns true if processed ok
    bool processSimpleMessage(Message& oMessage, Command& oCommand);    
    
    // interprets given message block converting it to a command block
    // returns true if processed ok
    bool processMessageBlock(MessageBlock& oMessageBlock, CommandBlock& oCommandBlock);
    
    // get topic id for given name
    int getTopicNumber(std::string topicName);
    // get topic name for given id
    std::string getTopicName(int topicId);
    // get the talker associated to the given topic id
    Talker* getTopicTalker(int topicId);
};
}
#endif
