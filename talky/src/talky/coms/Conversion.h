#ifndef __TALKY_CONVERSION_H
#define __TALKY_CONVERSION_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace talky
{
/** 
 * Base class used to build communications messages and commands. 
 */
class Conversion
{
protected:    
    // presence flags
    bool bhasTopic;                       /*! flag indicating the message has a topic field  */
    bool bhasCategory;                  /*! flag indicating the message has a category field  */
    bool bhasConcept;                   /*! flag indicating the message has a concept field  */
    bool bhasQuantity;                   /*! flag indicating the message has a quantity field  */  
    int numFieldsPresent;               /*! number of fields present in message */      
    bool bmissingFields;                /*! flag indicating the message has missing fields */
    // validity flags
    bool bvalidTopic;                       /*! flag indicating the topic field was interpreted  */
    bool bvalidCategory;                  /*! flag indicating the category field was interpreted */
    bool bvalidConcept;                   /*! flag indicating the concept field was interpreted */
    bool bvalidQuantity;                   /*! flag indicating the quantity field was interpreted */  
    int numFieldsInterpreted;            /*! number of fields interpreted in message */
        
public:
    Conversion();    
    
    void resetFlags();
    void resetPresenceFlags();
    void resetValidityFlags();

    void setTopicPresence(bool value);
    void setCategoryPresence(bool value);
    void setConceptPresence(bool value);
    void setQuantityPresence(bool value);      
    bool hasTopic() {return bhasTopic;};
    bool hasCategory() {return bhasCategory;};
    bool hasConcept() {return bhasConcept;};
    bool hasQuantity() {return bhasQuantity;};

    void setTopicValidity(bool value);
    void setCategoryValidity(bool value);
    void setConceptValidity(bool value);
    void setQuantityValidity(bool value);      
    bool isValidTopic() {return bvalidTopic;};
    bool isValidCategory() {return bvalidCategory;};
    bool isValidConcept() {return bvalidConcept;};
    bool isValidQuantity() {return bvalidQuantity;};
    
    void setMissingFields() {bmissingFields = true;};
    bool hasMissingFields() {return bmissingFields;};
    
    // check if conversion has all required fields
    bool isComplete();
    // check if conversion was fully interpreted
    bool isInterpreted();
    
    std::string toStringValidity();
};
}
#endif
