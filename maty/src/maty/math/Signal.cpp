/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/Signal.h"

namespace maty
{
Signal::Signal()
{    
    freq = 1.0;    
    clockFreq = 10.0;
    sectors = 1;
    phase = 0;
}

void Signal::setFrequency(float value)
{
    if (value >= 0.0)
    {
        freq = value;
        tune();
    }    
}

void Signal::setSectors(int value)
{
    if (value > 0)
    {
        sectors = value;
        tune();
    }            
}

void Signal::setPhase(int value)
{
    if (value > -360 && value < 360)
        phase = value;
}

void Signal::tune()
{
    angle4tic = 360.0 * freq / clockFreq;
    angle4sector = 360.0 / sectors;
}

void Signal::reset(Clock& oClock)
{
    // retune for clock frequency
    clockFreq = oClock.getFrequency();
    tune();
    
    // start counters
    angle = phase;  
    sector = 0;
    completion = 0.0;
    lastTic = oClock.getTics();
}

int Signal::sense(Clock& oClock)
{
    // compute elapsed tics
    int tics = oClock.getTics() - lastTic;
    lastTic = oClock.getTics();
    // protect against clock roof overstepping
    if (tics < 0)
        tics += oClock.getTicsRoof();

    // evolve angle
    angle += tics*angle4tic;
    // but watch limit
    while (angle >= 360.0)
        angle -= 360.0;

    // update sector and completion 
    float fsector = angle / angle4sector;
    sector = (int)fsector;
    completion = fsector - sector;    

    return sector;
}
}