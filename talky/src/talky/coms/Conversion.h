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
    bool bhasTopic;                       /*! flag indicating the message has a topic field  */
    bool bhasCategory;                  /*! flag indicating the message has a category field  */
    bool bhasConcept;                   /*! flag indicating the message has a concept field  */
    bool bhasValue;                       /*! flag indicating the message has a value field  */  
    int numFieldsPresent;
    // interpretation
    bool bvalidTopic;                       /*! flag indicating the topic field was interpreted  */
    bool bvalidCategory;                  /*! flag indicating the category field was interpreted */
    bool bvalidConcept;                   /*! flag indicating the concept field was interpreted */
    bool bvalidValue;                       /*! flag indicating the value field was interpreted */  
    int numFieldsInterpreted;
    int numFieldsMissing;
        
public:
    Conversion();    
    
    void resetPresenceFlags();
    void resetValidityFlags();

    void setTopicPresence(bool val);
    void setCategoryPresence(bool val);
    void setConceptPresence(bool val);
    void setValuePresence(bool val);      
    bool hasTopic() {return bhasTopic;};
    bool hasCategory() {return bhasCategory;};
    bool hasConcept() {return bhasConcept;};
    bool hasValue() {return bhasValue;};

    void setTopicValidity(bool val);
    void setCategoryValidity(bool val);
    void setConceptValidity(bool val);
    void setValueValidity(bool val);      
    bool isValidTopic() {return bvalidTopic;};
    bool isValidCategory() {return bvalidCategory;};
    bool isValidConcept() {return bvalidConcept;};
    bool isValidValue() {return bvalidValue;};
    
    // check if conversion has all required fields
    bool isComplete();
    // check if conversion was fully interpreted
    bool isInterpreted();
    
    std::string toStringValidity();
};
}
#endif
