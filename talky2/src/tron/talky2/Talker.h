#ifndef __TALKY2_TALKER_H
#define __TALKY2_TALKER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include <string>

#include "tuly/utils2/CodeMap.h"

namespace tron
{
/** 
 * Base class used to build & interpret messages of a given node topic.
 */
class Talker
{
public:
    static const int MSG_FIELDS = 2;                    /*! number of fields in message */ 
    static const std::string FIELD_SEPARATOR;      /*! character used to separate fields in message */
    
protected:
    static log4cxx::LoggerPtr logger;
    int node;                                              /*! associated node */    
    int topic;                                              /*! associated topic */    
    std::string name;                                  /*! talker name */     
    tuly::CodeMap oCodeMap;                      /*! code map for known concepts */    
    
public:
    Talker();              	
    Talker(int node, int topic);              	
    //~Talker();

    int getNode() {return node;};    
    int getTopic() {return topic;};        
    std::string getName() {return name;};
    
    // build message with given code and value
    // returns true if message could be built
    bool buildMessage(int code, float value, std::string& message);

    // interprets given message informing given code and value
    // returns true if message could be interpreted
    bool interpretMessage(std::string message, int& code, float& value);
    
    // show all concepts known by the talker
    void showKnowledge();
    
protected:
    // fill maps with knowledge (mandatory for any talker)
    virtual void buildKnowledge() = 0;              	
    // add concept to talker knowledge
    void addConcept(int code, std::string name);        
    // complete talker name with topic word
    virtual void completeName() = 0;
};
}
#endif
