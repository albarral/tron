#ifndef __TALKY_COMMAND_H
#define __TALKY_COMMAND_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace talky
{
/** 
 * Class used to represent a communications command.
 */
class Command
{
public:    
    // states of command while being processed
    enum eCmdState {
        eCMD_INCOMPLETE,                      /*! command lacks some mandatory field */
        eCMD_COMPLETE_SIMPLE,             /*! command has all mandatory fields (pending processing) */
        eCMD_COMPLETE_EXTENDED,        /*! command has all mandatory and optional fields (pending processing) */
        eCMD_PROCESSED_KO,               /*! command processingn failed (some data unknown) */  
        eCMD_PROCESSED_OK};             /*! command processing was ok */
    
private:    
    int topic;                      /*! topic  */
    int category;                /*! category in topic  */
    int concept;                  /*! concept in category */    
    int value;                     /*! measure value for the concept */
    int status;                     /*! command processing state (eCmdState) */    
    bool bhasTopic;             /*! flag indicating the command has a topic field  */
    bool bhasCategory;        /*! flag indicating the command has a category field  */
    bool bhasConcept;         /*! flag indicating the command has a concept field  */
    bool bhasValue;             /*! flag indicating the command has a value field  */  

        
public:
    Command();        
    // create simple command
    Command(int topic, int category, int concept);
    // create extended command
    Command(int topic, int category, int concept, int val);
    
    int getTopic() {return topic;};
    int getCategory() {return category;};
    int getConcept() {return concept;};
    int getValue() {return value;};
    int getStatus () {return status;};

    bool hasTopic() {return bhasTopic;};
    bool hasCategory() {return bhasCategory;};
    bool hasConcept() {return bhasConcept;};
    bool hasValue() {return bhasValue;};

    void resetFields();
    void setTopic(int val);
    void setCategory(int val);
    void setConcept(int val);
    void setValue(int val);                
    void setStatus(int info) {status = info;};

    // checks existence of required command fields
    void checkFields();
    
    // check if command has all required fields
    bool isCommandComplete();
    // check if command was fully processed
    bool isCommandProcessed();

    std::string toString();
};
}
#endif
