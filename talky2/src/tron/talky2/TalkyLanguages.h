#ifndef __TALKY2_TALKY_LANGUAGES_H
#define __TALKY2_TALKY_LANGUAGES_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/talky2/Talker.h"

namespace tron
{
// Class used to create talkers for all talky languages.
class TalkyLanguages 
{
private:    
    static log4cxx::LoggerPtr logger;

public:
    // create talker for the specified node & topic
    static Talker* createTalker(int node, int topic);        
    
private:
    // create talker for specific arm topic
    static Talker* createTalker4ArmTopic(int topic);
    // create talker for specific body topic
    static Talker* createTalker4BodyTopic(int topic);
};

}
#endif
