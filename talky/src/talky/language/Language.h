#ifndef __TALKY_LANGUAGE_H
#define __TALKY_LANGUAGE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <map>
#include <string>

#include "talky/language/Slang.h"

namespace talky
{
/** 
 * Base class used to represent a language. 
 * A language represents a single topic, including its categories and concepts. 
 * A slang is a language section that represents a single category.
 * So a language is composed by slangs.
 */
class Language
{    
protected:
    int topic;               /*! topic represented by this language */        
    std::map<int, std::string> mapCategories;      /*! map of category names */    
    std::map<int, Slang> mapSlangs;     /*! map of slangs, one per category */
    
public:
    Language();              	
    ~Language();

    void reset();    
    // set represented topic
    void setTopic(int topic);
    int getTopic() {return topic;}; 
    
    std::map<int, std::string>& getMapCategories() {return mapCategories;};
    std::map<int, Slang>& getMapSlangs() {return mapSlangs;};

    // get name of given category
    std::string getCategoryName(int category);   
    // get slang of given category
    Slang& getCategorySlang(int category);
    
    // build language
    virtual void build() = 0;
    std::string toString();

protected:
    // adds name for given category
    void addCategory(int category, std::string name);
    // adds slang for given category
    void addSlang(int category, Slang& oSlang);    
};
}
#endif
