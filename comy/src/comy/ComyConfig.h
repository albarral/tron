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
        static const std::string comsFilenameCS;     // name of file used for client-server communications
        static const std::string comsFilenamePS;     // name of file used for publish-subscribe communications

private:                
        std::string comsPathCS;     // file path used for client-server communications
        std::string comsPathPS;     // file path used for publish-subscribe communications
        
    public:
        ComyConfig();
        //~ComyConfig();
                
        std::string getComsBasePath();
        std::string getClientServerComsPath() {return comsPathCS;}        
        std::string getPubSubComsPath() {return comsPathPS;}        
};

}

#endif
