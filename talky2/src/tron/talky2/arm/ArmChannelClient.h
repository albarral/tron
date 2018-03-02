#ifndef __TALKY2_ARM_CHANNELCLIENT_H
#define __TALKY2_ARM_CHANNELCLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/channel/ChannelClient.h"

namespace tron
{
// Class to implement client functionality for a specific arm topic (using a dedicated channel).
class ArmChannelClient : public ChannelClient
{            
public:
    ArmChannelClient(int topic);
    //~ArmChannelClient();
    
private:
    void createTalker4ArmTopic(int topic);
    
};

}
#endif
