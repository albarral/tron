#ifndef __TALKY_SLANG_H
#define __TALKY_SLANG_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <map>
#include <string>

namespace talky
{
/** 
 * Class used to represent a slang. The set of names used to represent concepts.
 */
class Slang
{    
private:
    int category;                           /*! represented category */    
    std::map<int, std::string> mapWords;      /*! map of concept names */    
    
public:
    Slang();              	
    ~Slang();

    void reset();    
    // set represented category
    void setCategory(int category);
    int getCategory() {return category;};    
    std::map<int, std::string>& getMapWords() {return mapWords;};
    
    // returns name of given concept
    std::string getConceptName(int concept);    
    // adds name for given concept
    void addWord(int concept, std::string name);

    std::string toString();
};
}
#endif
