/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::invalid_argument

#include "talky/coms/StringUtil.h"

namespace talky
{
std::vector<std::string> StringUtil::split(std::string text, std::string separator)
{        
    std::vector<std::string> listTokens; 

    // split text in tokens (separated by separator)
    std::string::size_type orig = 0;
    std::string::size_type pos;
    bool bdone = false;    
    while (!bdone)
    {
        // search separator
        pos = text.find_first_of(separator, orig);

         // if found, get token
        if (pos != std::string::npos)
            listTokens.push_back(text.substr(orig, pos-orig));
        // otherwise, get the last token
        else
        {
            listTokens.push_back(text.substr(orig));
            bdone = true; 
        }

        orig = pos+1;
    }
    
    return listTokens;
}

std::deque<std::string> StringUtil::split2(std::string text, std::string separator)
{
    std::deque<std::string> seqTokens; 

    // split text in tokens (separated by separator)
    std::string::size_type orig = 0;
    std::string::size_type pos;
    bool bdone = false;    
    while (!bdone)
    {
        // search separator
        pos = text.find_first_of(separator, orig);

         // if found, get token
        if (pos != std::string::npos)
            seqTokens.push_back(text.substr(orig, pos-orig));
        // otherwise, get the last token
        else
        {
            seqTokens.push_back(text.substr(orig));
            bdone = true; 
        }

        orig = pos+1;
    }
    
    return seqTokens;    
}

bool StringUtil::convert2Integer(std::string number, int& value)
{        
    try
    {
        // do the conversion
        value = std::stoi(number);
        return true;
    }
    catch (std::invalid_argument) 
    {
        // text is not numeric, conversion failed
        return false;
    }
}

bool StringUtil::convert2Float(std::string number, float& value)
{        
    try
    {
        // do the conversion
        value = std::stof(number);
        return true;
    }
    catch (std::invalid_argument) 
    {
        // text is not numeric, conversion failed
        return false;
    }
}

std::string StringUtil::getBooleanValue(bool bvalue)
{
    return  (bvalue ? "y" : "n");
}

}
