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
    tron::CodeMap oCodeMap;                    /*! knowledge code map */    
    
public:
    CodeInterpreter();              	
    ~CodeInterpreter();

    bool isEnabled() {return benabled;};
    
    // clear interpreter knowledge
    void clearKnowledge();
    // adds given codes to the interpreter knowledge
    void addKnowledge(std::vector<Code> listCodes);
    // adds given code to the interpreter knowledge
    void addKnowledge(int codeId, std::string codeName);
    
    // search the code with the given name, return its id if found or -1 otherwise
    int interpretCode(std::string& word);

    // search the code with the given id, return its name if found or empty string otherwise
    std::string writeCode(int number);
    
    // get description of the interpreter knowledge
    std::string describeKnowledge();    
};
}
#endif
