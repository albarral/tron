#ifndef __COMY_CONFIG_H
#define __COMY_CONFIG_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace comy
{
class ComyConfig 
{
public: 
        static const std::string comsBaseFolder;      // base folder for all communication files
        static const std::string comsFileExtension;    // extension for communication files

private:                
        std::string comsBasePath;     // file path used for client-server communications
        
    public:
        ComyConfig();
        //~ComyConfig();
                
        std::string getComsBasePath() {return comsBasePath;};

private:
        void setComsBasePath();
    
};

}

#endif
