#ifndef __TRON_SIGNALS_OSCILLATOR_H
#define __TRON_SIGNALS_OSCILLATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/signals/Signal2.h"

namespace tron
{
// Extension of Signal class used to produce periodic signals of specified span and frequency.
// The oscillator can be symmetric (signal in [-span/2, span/2] range) or absolute (signal in [0, span] range).
// A phase can be set to start the oscillator at a desired position.
class Oscillator : public Signal2
{
private:
    // parameters
    float freq;     // oscillation frequency (Hz))
    float span;     // span of signal
    float phase;   // oscillator phase
    bool bsymmetric;     // symmetric vs absolute oscillator
    // logic
    float min;      // minimum signal value
    float max;      // maximum signal value
    float k;        // slope of signal change (units/ms)
    bool bup;     // sign of signal change (true positive, false negative)

public:
    Oscillator();

    float getFrequency() {return freq;};
    float getSpan() {return span;};
    float getPhase() {return phase;};
    bool getSymmetric() {return bsymmetric;};
    
    void setFrequency(float value);
    void setSpan(float value);
    void setPhase(int angle);
    void setSymmetry(bool value);

    virtual void reset(); 
    virtual void update();

    virtual std::string toString();
    
private:    
    // recompute oscillator values
    void tune();
    // advance quantity in present direction
    // if limit reached, change direction and return unused quantity
    float advance(float quantity);
};
}
#endif
