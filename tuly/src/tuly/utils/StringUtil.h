#ifndef __TULY_STRINGUTIL_H
#define __TULY_STRINGUTIL_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

namespace tuly
{
// Class with string utilities.
class StringUtil
{
public:
        // splits a text into a list of string elements using the specified separator
        // if separator not found, a single element list (with the whole string) is returned
        static std::vector<std::string> split(std::string text, std::string separator);

        // converts a numeric string to its integer value
        // if conversion fails (not an integer number), false is returned
        static bool convert2Integer(std::string number, int& value);

        // converts a numeric string to its float value
        // if conversion fails (not a float number), false is returned
        static bool convert2Float(std::string number, float& value);
};

}    
#endif
