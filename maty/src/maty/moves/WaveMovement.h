#ifndef __MATY_MOVES_WAVE_MOVEMENT_H
#define __MATY_MOVES_WAVE_MOVEMENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/moves/CyclicMovement.h"
 
namespace maty
{
// Class used to generate wave cyclic movements.
// It extends from CyclicMovement.    
class WaveMovement : public CyclicMovement
{  
public:  
    WaveMovement();
    //~WaveMovement();
    
    // create linear movement
    void createLine(float freq, float amplitude, float angle); 
    // create wave movement
    void createWave(float freq, float amplitude, float relFactor, float angle); 
};
}
#endif
