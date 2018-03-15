#ifndef __TALKY2_BODYCLIENT_H
#define __TALKY2_BODYCLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/talky2/channel/ChannelClient.h"
#include "tron/robot/clients/TronBodyClient.h"

namespace tron
{
// Body client class (implementing TronBodyClient interface) to control the body roles node.
class BodyClient : public TronBodyClient
{    
private:
    static log4cxx::LoggerPtr logger;
    ChannelClient* pExpressiveChannelClient;
    ChannelClient* pArtisticChannelClient;
    ChannelClient* pExtraChannelClient;
        
public:
    BodyClient();
    ~BodyClient();

    // expressive topic ...
    // express given feeling (feeling id)
    virtual bool expressFeeling(int value);
    // stop expressing feeling
    virtual bool stopExpression();

    // artistic topic ...
    // make given artistic figure (figure id)
    virtual bool makeFigure(int value);
    // set frequency of artistic movement (Hz)
    virtual bool setFigureFreq(float value);
    // set amplitude of artistic movement (degrees)
    virtual bool setFigureAmplitude(float value);
    // set orientation of artistic movement (degrees)
    virtual bool setFigureAngle(float value);
    // set shape factor of artistic movement 
    virtual bool setFigureFactor(float value);
    // stop artistic movement
    virtual bool stopFigure();

    // extra topic ...    
    // full stop of control actions 
    virtual bool fullStop();
    // end control process
    virtual bool endNode();        
};

}
#endif
