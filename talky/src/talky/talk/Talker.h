#ifndef __TALKY_TALKER_H
#define __TALKY_TALKER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include <map>
#include <string>

#include "talky/talk/SlangTalker.h"
#include "talky/coms/Message.h"
#include "talky/coms/Command.h"
#include "talky/base/Category.h"
#include "talky/base/Topic.h"

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
    void build(Topic& oTopic);
    
    // converts given communication message in a command 
    // elements processed: category 
    // uses proper slang talker to interpret elements of the category
    void processMessage(Message& oMessage, Command& oCommand);    
    
    // converts given command in a communication message
    void buildMessage(Command& oCommand, Message& oMessage);

    // checks if talker knows given category
    bool knowsCategory(int categoryId);    
    
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
