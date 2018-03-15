#ifndef __TRON_WIRE2_CONFIG_H
#define __TRON_WIRE2_CONFIG_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron
{
class Wire2Config 
{
public: 
        static const std::string comsBaseFolder;      // base folder for all communication files
        static const std::string comsFileExtension;    // extension for communication files

private:                
        std::string comsBasePath;     // file path used for client-server communications
        
    public:
        Wire2Config();
        //~Wire2Config();
                
        std::string getComsBasePath() {return comsBasePath;};

private:
        void setComsBasePath();
    
};

}

#endif
