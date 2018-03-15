#ifndef __MATY_SIGNALS_SOFTOSCILLATOR_H
#define __MATY_SIGNALS_SOFTOSCILLATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "maty/signals/Oscillator.h"

namespace maty
{
// Class implementing a senoidal oscillator. 
// It uses an absolute internal oscillator to evolve a circular angle, then applies the sinus function to that angle to achieve a soft oscillation.
class SoftOscillator 
{
private:
    Oscillator oOscillator; // internal oscillator [0, 360]
    float output;    

public:
    SoftOscillator();

    float getFrequency();
    float getOutput() {return output;};

    void setFrequency(float value);
    void reset(); 
    void update();

    std::string toString();
};
}
#endif
