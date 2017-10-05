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
private:    
    const int INVALID_VALUE = -1;
    int topic;                      /*! topic  */
    int category;                /*! category in topic  */
    int concept;                  /*! concept in category */    
    int value;                     /*! measure value for the concept */
    bool bhasTopic;             /*! flag indicating the command has a topic field  */
    bool bhasCategory;        /*! flag indicating the command has a category field  */
    bool bhasConcept;         /*! flag indicating the command has a concept field  */
    bool bhasValue;             /*! flag indicating the command has a value field  */  

        
public:
    Command();        
    Command(int topic, int category, int concept, int val);
    
    int getTopic() {return topic;};
    int getCategory() {return category;};
    int getConcept() {return concept;};
    int getValue() {return value;};

    bool hasTopic() {return bhasTopic;};
    bool hasCategory() {return bhasCategory;};
    bool hasConcept() {return bhasConcept;};
    bool hasValue() {return bhasValue;};

    void resetFields();
    void setTopic(int val);
    void setCategory(int val);
    void setConcept(int val);
    void setValue(int val);                
    
    std::string toString();
};
}
#endif
