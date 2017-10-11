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
    private:                
        std::string comsFilename1;     // name of file used for client-server communications
        std::string comsFilename2;     // name of file used for publish-subscribe communications
        
    public:
        ComyConfig();
        //~ComyConfig();
                
        std::string getComsFolder();
        std::string getComsFilename1() {return comsFilename1;}        
        std::string getComsFilename2() {return comsFilename2;}        
};

}

#endif
