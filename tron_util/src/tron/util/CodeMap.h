#ifndef __TRON_UTIL_CODEMAP_H
#define __TRON_UTIL_CODEMAP_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <map>
#include <string>

namespace tron
{
/** 
 * Utility class used to manage code maps (mapping codes & names). 
 */
class CodeMap
{
protected:
    std::map<int, std::string> mapCodes;      /*! map of codes (code - name) */    
    std::map<std::string, int> mapNames;      /*! map of names (name - code) */    
    
public:
    CodeMap() {};              	
    ~CodeMap();

    void reset();
    
    // add code to map
    void addCode(int code, std::string name);        
    // return number of stored codes
    int getSize(); 
    
    // find name for given code, returns false if unknown
    bool getName4Code(int code, std::string& name);
    // find code with given name, returns false if unknown
    bool getCode4Name(std::string name, int& code);
    
    //  return description of code map
    virtual std::string toString();
};
}
#endif
