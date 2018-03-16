#ifndef __MATY_SIGNALS_OSCILLATOR_H
#define __MATY_SIGNALS_OSCILLATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "maty/signals/Signal2.h"

namespace maty
{
// Extension of Signal class used to produce periodic signals of specified frequency.     
class Oscillator : public Signal2
{
private:
    // parameters
    float freq;     // oscillation frequency (Hz))
    float span;     // span of signal
    bool bsymmetric;     // symmetric oscillations [-span/2, span/2] vs absolute oscillation [0, span]
    // logic
    float min;      // minimum signal value
    float max;      // maximum signal value
    float k;        // slope of signal change (units/ms)
    bool bup;     // sign of signal change (true positive, false negative)

public:
    Oscillator();

    float getFrequency() {return freq;};
    float getSpan() {return span;};
    bool getSymmetric() {return bsymmetric;};
    
    void setFrequency(float value);
    void setSpan(float value);
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
