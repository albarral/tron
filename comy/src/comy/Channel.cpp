/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "comy/Channel.h"

namespace comy
{

Channel::Channel()
{    
    type = Channel::eCHANNEL_UNDEFINED;
    topic = "";
    category = "";
    name = "";
}

void Channel::setChannel(int type, std::string topic, std::string category)
{
    // build channel name
    if (type > Channel::eCHANNEL_UNDEFINED && type < Channel::eCHANNEL_DIM)
    {
        this->type = type;
        this->topic = topic;
        this->category = category;
        
        std::string prefix; 
        switch (type)
        {
            case Channel::eCHANNEL_SERVED:
                prefix = "uni";                        
                break;
          
            case Channel::eCHANNEL_BROADCAST:
                prefix = "broad";                        
                break;
        }
        name = prefix + "_" + topic + "_" + category;
    }
}
}