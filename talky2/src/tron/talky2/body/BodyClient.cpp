/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/talky2/body/BodyClient.h"
#include "tron/talky2/body/ExpressiveTalker.h"
#include "tron/talky2/body/ArtisticTalker.h"
#include "tron/talky2/BasicTalker.h"
#include "tron/robot/RobotNodes.h"
#include "tron/robot/topics/BodyTopics.h"

using namespace log4cxx;

namespace tron
{
LoggerPtr BodyClient::logger(Logger::getLogger("tron.talky2"));

BodyClient::BodyClient()
{    
    int node = RobotNodes::eNODE_BODYROLE;
    pExpressiveChannelClient = new ChannelClient(node, BodyTopics::eBODY_EXPRESSIVE);
    pArtisticChannelClient = new ChannelClient(node, BodyTopics::eBODY_ARTISTIC);
    pExtraChannelClient = new ChannelClient(node, BodyTopics::eBODY_EXTRA);
}

BodyClient::~BodyClient()
{    
    if (pExpressiveChannelClient != 0)
        delete(pExpressiveChannelClient);
    if (pArtisticChannelClient != 0)
        delete(pArtisticChannelClient);
    if (pExtraChannelClient != 0)
        delete(pExtraChannelClient);
}

// EXPRESSIVE TOPIC ...

bool BodyClient::expressFeeling(int value)
{    
    LOG4CXX_DEBUG(logger, "BodyClient: express feeling > " << std::to_string(value));
    return pExpressiveChannelClient->sendMessage(ExpressiveTalker::eEXPRESS_FEELING, (float)value);
}

bool BodyClient::stopExpression()
{    
    LOG4CXX_DEBUG(logger, "BodyClient: stop expression > ");
    return pExpressiveChannelClient->sendMessage(ExpressiveTalker::eEXPRESS_HALT, 0.0);
}

// ARTISTIC TOPIC ...

bool BodyClient::makeFigure(int value)
{    
    LOG4CXX_DEBUG(logger, "BodyClient: make figure > " << std::to_string(value));
    return pExpressiveChannelClient->sendMessage(ArtisticTalker::eARTISTIC_FIGURE, value);
}

bool BodyClient::setFigureFreq(float value)
{    
    LOG4CXX_DEBUG(logger, "BodyClient: set figure freq > " << std::to_string(value));
    return pExpressiveChannelClient->sendMessage(ArtisticTalker::eARTISTIC_FREQ, value);
}

bool BodyClient::setFigureAmplitude(float value)
{    
    LOG4CXX_DEBUG(logger, "BodyClient: set figure amp > " << std::to_string(value));
    return pExpressiveChannelClient->sendMessage(ArtisticTalker::eARTISTIC_SIZE, value);
}

bool BodyClient::setFigureAngle(float value)
{    
    LOG4CXX_DEBUG(logger, "BodyClient: set figure angle > " << std::to_string(value));
     return pArtisticChannelClient->sendMessage(ArtisticTalker::eARTISTIC_ORIENTATION, value);
}

bool BodyClient::setFigureFactor(float value)
{    
    LOG4CXX_DEBUG(logger, "BodyClient: set figure factor > " << std::to_string(value));
     return pArtisticChannelClient->sendMessage(ArtisticTalker::eARTISTIC_RELFACTOR, value);
}

bool BodyClient::stopFigure()
{    
    LOG4CXX_DEBUG(logger, "BodyClient: stop figure > ");
     return pArtisticChannelClient->sendMessage(ArtisticTalker::eARTISTIC_HALT, 0.0);
}

// EXTRA TOPIC ...

bool BodyClient::fullStop()
{
    LOG4CXX_DEBUG(logger, "BodyClient: full stop > ");     
    return pExtraChannelClient->sendMessage(BasicTalker::eBASIC_FULL_STOP, 0.0);        
}

bool BodyClient::endNode()
{
    LOG4CXX_DEBUG(logger, "BodyClient: end body node > ");     
    return pExtraChannelClient->sendMessage(BasicTalker::eBASIC_CONTROL_END, 0.0);        
}
}