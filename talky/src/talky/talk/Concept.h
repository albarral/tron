#ifndef __TALKY_CONCEPT_H
#define __TALKY_CONCEPT_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace talky
{
/** 
 * Class used to represent a concept. A concept has a meaning and a name.
 */
class Concept
{
private:    
    int topic;          /*! concept's topic  */
    int category;   /*! concept's category  */
    int meaning;       /*! concept's meaning */
    std::string name;      /*! concept's name */    
    bool bneedsValue;     /*! concept needs a value (a measure) */   
    
public:
    //Concept();        
    Concept(int topic, int category, int meaning, std::string name, bool bneedsValue);

    int getTopic() {return topic;};
    int getCategory() {return category;};
    int getMeaning() {return meaning;};
    std::string getName() {return name;};
    bool needsValue() {return bneedsValue;}; 
        
    std::string toString();
};
}
#endif
