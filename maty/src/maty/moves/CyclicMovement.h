#ifndef __MATY_MOVES_CYCLIC_MOVEMENT_H
#define __MATY_MOVES_CYCLIC_MOVEMENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/moves/CyclicComponent.h"
 
namespace maty
{
// Base class used to represent cyclic movements.
// Cyclic movements may be composed by two cyclic components (each with its own frequency, angle, amplitude and phase). In this case the dual flag is informed.
class CyclicMovement
{  
protected: 
    bool bdual;                                 // both components informed
    CyclicComponent oCyclicComponent1;     // primary cyclic component
    CyclicComponent oCyclicComponent2;     // secondary cyclic component
    
public:  
    CyclicMovement();
    //~CyclicMovement();

    bool isDual() {return bdual;}
    CyclicComponent& getPrimaryComponent() {return oCyclicComponent1;}
    CyclicComponent& getSecondaryComponent() {return oCyclicComponent2;};
    
    void updateFreq(float freq);
    void updateAmplitude(float amplitude);
    void updateAngle(float angle);
    void updateRelFactor(float factor); 
    
};
}
#endif
