#ifndef __TALKY_MESSAGE_H
#define __TALKY_MESSAGE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "talky/coms/Conversion.h"

namespace talky
{
/** 
 * Class used to represent a communications message. 
 */
class Message : public Conversion
{
private:    
    // field positions in message
    enum eMsgFields {
        eFIELD_TOPIC,                     /*! topic field (mandatory) */ 
        eFIELD_CATEGORY,              /*! category field (mandatory) */
        eFIELD_CONCEPT,                /*! concept field (mandatory) */
        eFIELD_QUANTITY,                     /*! quantity field (optional) */
        eFIELD_DIM};
        
    std::string rawText;                 /*! raw text of message */
    std::string topic;                      /*! topic  */
    std::string category;                /*! category in topic  */
    std::string concept;                  /*! concept in category */    
    std::string quantity;                     /*! quantity for the concept */

        
public:
    Message();    
    // create simple message
    Message(std::string topic, std::string category, std::string concept);
    // create extended message
    Message(std::string topic, std::string category, std::string concept, std::string quantity);
    
    void reset();
    
    void setRawText(std::string text) {rawText = text;};
    void setTopic(std::string word);
    void setCategory(std::string word);
    void setConcept(std::string word);
    void setQuantity(std::string word);      

    std::string getRawText() {return rawText;};
    std::string getTopic() {return topic;};
    std::string getCategory() {return category;};
    std::string getConcept() {return concept;};
    std::string getQuantity() {return quantity;};
    
    // build raw text from fields and return it
    void composeMessage();
    // extract fields from message's raw text
    void digestMessage();
        
    std::string toString();
    
private:
    void resetFields();    
};
}
#endif
