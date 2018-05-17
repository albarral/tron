#ifndef __TRON_UTIL_CODE_INTERPRETER_H
#define __TRON_UTIL_CODE_INTERPRETER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "tron/util/Code.h"
#include "tron/util/CodeMap.h"

namespace tron
{
/** 
 * Utility class used to interpret codes using a given code map.
 */
class CodeInterpreter
{
private:
    bool benabled;                                     /*! flag indicating the interpreter has a knowledge */    
    tron::CodeMap oCodeMap;                    /*! knowledge */    
    
public:
    CodeInterpreter();              	
    ~CodeInterpreter();

    bool isEnabled() {return benabled;};
    
    // set interpreter knowledge
    void setKnowledge(std::vector<Code> listCodes);
    // clear interpreter knowledge
    void reset();
    
    // search the code with the given name, return its id if found or -1 otherwise
    int interpretCode(std::string& word);

    // search the code with the given id, return its name if found or empty string otherwise
    std::string writeCode(int number);
    
    // get description of the interpreter knowledge
    std::string describeKnowledge();    
};
}
#endif
