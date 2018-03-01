/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "tuly/utils2/CodeMap.h"

namespace tuly
{
CodeMap::~CodeMap()
{
    reset();
}

void CodeMap::reset()
{
    mapCodes.clear();
    mapNames.clear();    
}

void CodeMap::addCode(int code, std::string name)
{
    // add code to maps
    mapCodes.emplace(code, name);    
    mapNames.emplace(name, code);    
}

bool CodeMap::getName4Code(int code, std::string& name)
{
    try 
    {
        // search code in codes map
        name = mapCodes.at(code);
        return true;
    }
    // return false if code not found
    catch (const std::out_of_range& oor) 
    {                
        return false;
    }                
}

bool CodeMap::getCode4Name(std::string name, int& code)
{
    try 
    {
        // search code in names map
        code = mapNames.at(name);
        return true;
    }
    // return false if code not found
    catch (const std::out_of_range& oor) 
    {                
        return false;
    }            
}        

std::string CodeMap::toString()
{
    std::string desc;
            
    // for each code, add code - name text
    for (auto& x: mapCodes) 
    {
        desc += std::to_string(x.first) + " - " + x.second + "\n";
    }    

    return desc;
}

}