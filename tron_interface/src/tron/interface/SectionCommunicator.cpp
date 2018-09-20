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

bool SectionCommunicator::tune4Node(int node, int section, Node& oNode)
{
    // set topics 
    this->node = node;
    this->section = section;
    
    Topic oTopic;
    NodeSection* pNodeSection = oNode.getSection(section);
    if (pNodeSection != nullptr)
    {
        int numChannels = pNodeSection->getNumChannels();
        // for each channel in section
        for (int channel=0; channel<numChannels; channel++)
        {
            // set its topic 
            oTopic.set(node, section, channel, topicType);
            // and add a channel reader for it
            if (oNode.buildTopicName(oTopic))
            {
                addChannel(oTopic.getTopicName());      
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