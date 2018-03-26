#ifndef __TRON_MOVES_CYCLIC_MOVEMENT_H
#define __TRON_MOVES_CYCLIC_MOVEMENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/CyclicComponent.h"
 
namespace tron
{
// Base class used to represent cyclic movements.
// Cyclic movements may be composed by two cyclic components (each with its own frequency, angle, amplitude and phase). In this case the dual flag is informed.
class CyclicMovement
{  
protected: 
    bool bdual;                                 // both components informed
    maty::CyclicComponent oCyclicComponent1;     // primary cyclic component
    maty::CyclicComponent oCyclicComponent2;     // secondary cyclic component
    
public:  
    CyclicMovement();
    //~CyclicMovement();

    bool isDual() {return bdual;}
    maty::CyclicComponent& getPrimaryComponent() {return oCyclicComponent1;}
    maty::CyclicComponent& getSecondaryComponent() {return oCyclicComponent2;};
    
    void updateFreq(float freq);
    void updateAmplitude(float amplitude);
    void updateAngle(float angle);
    void updateRelFactor(float factor); 
    
};
}
#endif
