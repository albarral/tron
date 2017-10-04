#ifndef __TALKY_TALKER_H
#define __TALKY_TALKER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include <map>
#include <string>

#include "talky/coms/SlangTalker.h"
#include "talky/coms/Message.h"
#include "talky/coms/Command.h"
#include "talky/talk/Category.h"
#include "talky/talk/TalkTopic.h"


namespace talky
{
/** 
 * Class used to interpret and speak a topic. 
 * It uses slang talkers, one for each topic category.
 */
class Talker
{    
private:
    static log4cxx::LoggerPtr logger;
    int topic;                                           /*! represented category */    
    std::map<std::string, int> mapCategoryNumbers;      /*! map of category numbers */    
    std::map<int, std::string> mapCategoryNames;        /*! map of category names */    
    std::map<int, SlangTalker> mapSlangTalkers;         /*! map of slang talkers */    
    
public:
    Talker();              	
    ~Talker();

    void reset();    
    void setTopic(int topic) {this->topic = topic;};
    int getTopic() {return topic;};    

    // builds talker for given topic
    void build(TalkTopic& oTalkTopic);
    
    // interprets given message, converting it to a standard command
    // returns true if interpretation was ok
    bool processMessage(Message& oMessage, Command& oCommand);    
    
    // converts given command in a communication's message
    // returns true if conversion was ok
    bool buildMessage(Command& oCommand, Message& oMessage);

    // checks if given category is understood by this topic interpreter
    bool understandsSlang(std::string categoryName);    
    
    // show all categories known by the talker
    std::string showKnowledge();

private:
    // get category id for given name
    int getCategoryNumber(std::string categoryName);
    // get category name for given id
    std::string getCategoryName(int categoryId);    
    // get the slang talker associated to the given category
    SlangTalker* getCategorySlangTalker(int categoryId);

};
}
#endif
