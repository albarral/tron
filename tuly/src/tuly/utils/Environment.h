#ifndef __TULY_ENVIRONMENT_H
#define __TULY_ENVIRONMENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tuly 
{
class Environment
{
public:
    //Environment ();
    //~Environment();

    // obtains user's home path
    static std::string getHomePath();
    
    static void cleanFolder(std::string path);
};

}		
#endif
