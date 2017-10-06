#ifndef __TALKY_MESSAGE_H
#define __TALKY_MESSAGE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace talky
{
/** 
 * Class used to represent a communications message. 
 */
class Message
{
public:    
    // states of message while being processed
    enum eMsgState {
        eSTATE_INCOMPLETE,                      /*! message lacks some mandatory field */
        eSTATE_COMPLETE_SIMPLE,             /*! message has all mandatory fields (pending interpretation) */
        eSTATE_COMPLETE_EXTENDED,        /*! message has all mandatory and optional fields (pending interpretation) */
        eSTATE_INTERPRETED_KO,               /*! message interpretation failed (some data unknown) */  
        eSTATE_INTERPRETED_OK};             /*! message interpretation was ok */

private:    
    // field positions in message
    enum eMsgFields {
        eMSG_TOPIC,                     /*! topic field (mandatory) */ 
        eMSG_CATEGORY,              /*! category field (mandatory) */
        eMSG_CONCEPT,                /*! concept field (mandatory) */
        eMSG_VALUE,                     /*! value field (optional) */
        eMSG_DIM};
        
    std::string rawText;                 /*! raw text of message */
    std::string topic;                      /*! topic  */
    std::string category;                /*! category in topic  */
    std::string concept;                  /*! concept in category */    
    std::string value;                     /*! measure value for the concept */
    int status;                               /*! message processing state (eMsgState) */
    bool bhasTopic;                       /*! flag indicating the message has a topic field  */
    bool bhasCategory;                  /*! flag indicating the message has a category field  */
    bool bhasConcept;                   /*! flag indicating the message has a concept field  */
    bool bhasValue;                       /*! flag indicating the message has a value field  */  

        
public:
    Message();        
    Message(std::string topic, std::string category, std::string concept);
    Message(std::string topic, std::string category, std::string concept, std::string value);
    
    std::string getRawText() {return rawText;};
    std::string getTopic() {return topic;};
    std::string getCategory() {return category;};
    std::string getConcept() {return concept;};
    std::string getValue() {return value;};
    int getStatus () {return status;};

    bool hasTopic() {return bhasTopic;};
    bool hasCategory() {return bhasCategory;};
    bool hasConcept() {return bhasConcept;};
    bool hasValue() {return bhasValue;};

    void resetFields();
    void setTopic(std::string word);
    void setCategory(std::string word);
    void setConcept(std::string word);
    void setValue(std::string word);      
    void setStatus(int info) {status = info;};
    
    // build raw text from fields and return it
    void composeMessage();
    // extract fields from given raw text
    void splitMessage(std::string text);
    
    // check if message has all required fields
    bool checkMessageComplete();
    // check if message was fully interpreted
    bool checkMessageInterpreted();

    
    std::string toString();
};
}
#endif
