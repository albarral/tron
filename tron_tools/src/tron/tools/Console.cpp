/***************************************************************************
 *   Copyright (C) 2015 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <iostream>

#include "tron/tools/Console.h"

namespace tron 
{
void Console::write(std::string question)
{
    std::cout << question << std::endl;        
}

bool Console::checkInput()
{
    input = "";
    std::getline(std::cin, input);   
    return (!input.empty());
}
    
}