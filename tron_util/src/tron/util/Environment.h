#ifndef __TRON_UTIL_ENVIRONMENT_H
#define __TRON_UTIL_ENVIRONMENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron 
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
