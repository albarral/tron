#ifndef __TALKY_COMMAND_H
#define __TALKY_COMMAND_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "talky/coms/Conversion.h"

namespace talky
{
/** 
 * Class used to represent a communications command.
 */
class Command : public Conversion
{
private:    
    int topic;                      /*! topic  */
    int category;                /*! category in topic  */
    int concept;                  /*! concept in category */    
    float quantity;                  /*! quantity for the concept */
        
public:
    Command();        
    // create simple command
    Command(int topic, int category, int concept);
    // create extended command
    Command(int topic, int category, int concept, float quantity);
    
    void reset();    
    
    void setTopic(int value);
    void setCategory(int value);
    void setConcept(int value);
    void setQuantity(float value);                

    int getTopic() {return topic;};
    int getCategory() {return category;};
    int getConcept() {return concept;};
    float getQuantity() {return quantity;};
    
    std::string toString();

private:
    void resetFields();    
    
};
}
#endif
