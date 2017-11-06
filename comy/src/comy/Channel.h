#ifndef __COMY_CHANNEL_H
#define __COMY_CHANNEL_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace comy
{
// Class used to define a communications channel.
// Multichannel coms: A channel will always be dedicated to a given topic and category.
// Every channel has a unique name, which is built from its type, topic and category values.    
class Channel
{        
 public:     
    /*! channel types */
    enum eTypes
    {
        eCHANNEL_UNDEFINED,       
        eCHANNEL_SERVED,            /*! served point to point channel */
        eCHANNEL_BROADCAST,      /*! broadcast channel */
        eCHANNEL_DIM
    };    
    
private:
    int type;                   // channel type (one of eTypes)
    std::string topic;
    std::string category;
    std::string name;       // channel name
    
public:
    Channel();

    int getType() {return type;};
    std::string getTopic() {return topic;};
    std::string getCategory() {return category;};
    std::string getName() {return name;};
    // sets the channel 
    void setChannel(int type, std::string topic, std::string category);
    // checks if it's already informed
    bool isInformed () {return type != Channel::eCHANNEL_UNDEFINED;};
};
}
#endif
