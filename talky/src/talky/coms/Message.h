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
private:    
    // field positions in message
    enum eMsgFields {
        eMSG_TOPIC, 
        eMSG_CATEGORY,
        eMSG_CONCEPT, 
        eMSG_VALUE,
        eMSG_DIM};
    
    std::string rawText;                 /*! raw text of message */
    std::string topic;                      /*! topic  */
    std::string category;                /*! category in topic  */
    std::string concept;                  /*! concept in category */    
    std::string value;                     /*! measure value for the concept */
    bool bhasTopic;                       /*! flag indicating the message has a topic field  */
    bool bhasCategory;                  /*! flag indicating the message has a category field  */
    bool bhasConcept;                   /*! flag indicating the message has a concept field  */
    bool bhasValue;                       /*! flag indicating the message has a value field  */  

        
public:
    Message();        
    Message(std::string topic, std::string category, std::string concept, std::string value);
    
    std::string getRawText() {return rawText;};
    std::string getTopic() {return topic;};
    std::string getCategory() {return category;};
    std::string getConcept() {return concept;};
    std::string getValue() {return value;};

    bool hasTopic() {return bhasTopic;};
    bool hasCategory() {return bhasCategory;};
    bool hasConcept() {return bhasConcept;};
    bool hasValue() {return bhasValue;};

    void resetFields();
    void setTopic(std::string word);
    void setCategory(std::string word);
    void setConcept(std::string word);
    void setValue(std::string word);            
    
    // build raw text from fields and return it
    void composeMessage();
    // extract fields from given raw text
    void splitMessage(std::string text);
    
    std::string toString();
};
}
#endif
