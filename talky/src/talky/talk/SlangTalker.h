#ifndef __TALKY_SLANGTALKER_H
#define __TALKY_SLANGTALKER_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include <map>
#include <string>

#include "talky/coms/Message.h"
#include "talky/coms/Command.h"
#include "talky/base/Category.h"
#include "talky/base/Concept.h"

namespace talky
{
/** 
 * Class used to interpret and speak a slang, the language part associated a topic category.
 */
class SlangTalker
{    
private:
    static log4cxx::LoggerPtr logger;
    int category;                                           /*! represented category */    
    std::map<std::string, int> mapConceptNumbers;      /*! map of concept numbers */    
    std::map<int, std::string> mapConceptNames;      /*! map of concept names */    
    std::map<int, Concept> mapConcepts;      /*! map of concepts */    
    
public:
    SlangTalker();              	
    ~SlangTalker();

    void reset();    
    void setCategory(int category) {this->category = category;};
    int getCategory() {return category;};    

    // builds slang talker for given category
    void build(Category& oCategory);
    
    // converts given communication message in a command 
    // elements processed: concept and quantity
    void processMessage(Message& oMessage, Command& oCommand);        
    
    // converts given command in a communication message
    // elements processed: concept and quantity
    void buildMessage(Command& oCommand, Message& oMessage);

    // checks if given concept is understood by this slang interpreter
    bool understandsConcept(std::string conceptName);    
    
    // show all concepts known by the slang talker
    std::string showKnowledge();
    
private:
    // interprets quantity of given message
    // it informs the given command
    void processQuantity(Message& oMessage, Command& oCommand);    
    // builds quantity of given command
    // it informs the given command
    void buildQuantity(Command& oCommand, Message& oMessage);    

    // get concept id for given name
    int getConceptNumber(std::string conceptName);
    // get concept name for given id
    std::string getConceptName(int conceptId);        
    // get the concept associated to given id
    Concept* getTopicConcept(int conceptId);
    
};
}
#endif
