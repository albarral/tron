#ifndef __TRON_TOOLS_CONSOLE_H
#define __TRON_TOOLS_CONSOLE_H

/***************************************************************************
 *   Copyright (C) 2015 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron 
{
class Console
{
private:
    std::string output;   // text shown in the console
    std::string input;   // text captured from console    

public:
//    Console();
//    ~Console();

    // write something through the console
    void write(std::string text);
    // checks if there was an input (other than just return)
    bool checkInput();
    // gets the input captured through the console
    std::string getInput() {return input;}; 
};

}		
#endif
