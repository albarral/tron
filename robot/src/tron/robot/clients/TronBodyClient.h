#ifndef __TRON_ROBOT_BODYCLIENT_H
#define __TRON_ROBOT_BODYCLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

namespace tron
{
// Interface class for body clients
class TronBodyClient
{        
 public:     
    // expressive topic ...
    // express given feeling (feeling id)
    virtual bool expressFeeling(int value) = 0;
    // stop expressing feeling
    virtual bool stopExpression() = 0;

    // artistic topic ...
    // make given artistic figure (figure id)
    virtual bool makeFigure(int value) = 0;
    // set frequency of artistic movement (Hz)
    virtual bool setFigureFreq(float value) = 0;
    // set amplitude of artistic movement (degrees)
    virtual bool setFigureAmplitude(float value) = 0;
    // set orientation of artistic movement (degrees)
    virtual bool setFigureAngle(float value) = 0;
    // set shape factor of artistic movement 
    virtual bool setFigureFactor(float value) = 0;
    // stop artistic movement
    virtual bool stopFigure() = 0;
};
}
#endif
