/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/interface/SectionCommunicator.h"
#include "tron/topics/NodeSection.h"
#include "tron/topics/Topic.h"


using namespace log4cxx;

namespace tron
{
LoggerPtr SectionCommunicator::logger(Logger::getLogger("tron.interface"));

SectionCommunicator::SectionCommunicator(int topicType)
{    
    node = -1;
    section = -1;
    this->topicType = topicType;
    btuned = false;
}

//SectionCommunicator::~SectionCommunicator()
//{    
//}

bool SectionCommunicator::tune4Node(Node& oNode, int section)
{
    // set topics 
    node = oNode.getID();
    this->section = section;
    
    Topic oTopic;
    // get specific node section
    NodeSection* pNodeSection = oNode.getSection(section);
    if (pNodeSection != nullptr)
    {
        // for each channel in the section
        int numChannels = pNodeSection->getNumChannels();
        for (int channel=0; channel<numChannels; channel++)
        {
            // set topic for that channel
            oTopic.set(node, section, channel, topicType);
            std::string topicName = oTopic.build4Node(oNode);
            // and add a reader for it
            if (!topicName.empty())
            {
                addChannel(topicName);      
                btuned = true;
            }
            // break if wrong topic
            else
            {
                btuned = false;
                break;
            }
        }    
    }

    // connect all channels
    if (btuned)
        connect();
    
    return btuned;
}
}