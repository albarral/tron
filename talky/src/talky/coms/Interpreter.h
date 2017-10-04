#ifndef __TALKY_INTERPRETER_H
#define __TALKY_INTERPRETER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include <map>
#include <string>

#include "talky/coms/Talker.h"
#include "talky/coms/Message.h"
#include "talky/coms/Command.h"

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
    Message oMessage;                                       /*! processed message */
    Command oCommand;                                    /*! interpreted command */   
    
public:
    Interpreter();              	
    ~Interpreter();

    void reset();    

    // adds language capability for the given topic
    void addLanguage(int topicId);
    
    // interprets given message, converting it to a standard command
    // returns true if interpretation was ok
    bool processMessage(std::string text);    
    // gets interpreted command
    Command& getCommand() {return oCommand;};
    
    // converts given command in a communication message
    // returns true if conversion was ok
    bool buildMessage(Command& oCommandOut);
    // gets composed message
    Message& getMessage() {return oMessage;};

    // checks if given topic is understood by this interpreter
    bool understandsLanguage(std::string topicName);    
    
    // show all languages known by the interpreter
    void showKnowledge();
    
private: 
    // check if Message object has all required fields
    bool checkMessageComplete();
    // get topic id for given name
    int getTopicNumber(std::string topicName);
    // get topic name for given id
    std::string getTopicName(int topicId);
    // get the talker associated to the given topic id
    Talker* getTopicTalker(int topicId);
};
}
#endif
