#ifndef __TRON_SIGNALS_SENOIDAL_OSCILLATOR_H
#define __TRON_SIGNALS_SENOIDAL_OSCILLATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/signals/Oscillator.h"

namespace tron
{
// Class implementing a senoidal oscillator. 
// It internally works as a linear oscillator (not symmetric) that evolves an angle in the [0, 180] range. It then modulates the signal applying the sinus function to the angle.
class SenoidalOscillator : public Oscillator
{
private:
    float value2;       // modulated signal (senoidal form)   

public:
    SenoidalOscillator();

    float getValue2() {return value2;};

    virtual void reset(); 
    virtual void update();

    virtual std::string toString();
};
}
#endif
