/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/Code.h"

namespace tron
{
Code::Code()
{          
    id = -1;
    name = "";
}

Code::Code(int id, std::string name)
{          
    this->id = id;
    this->name = name;
}

//Code::~Code ()
//{
//}

std::string Code::toString()
{
    return ("Code: " + std::to_string(id) + " - " + name);    
}
}




