#ifndef __TRON_MOVES_CIRCULAR_MOVEMENT_H
#define __TRON_MOVES_CIRCULAR_MOVEMENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/moves/CyclicMovement.h"
 
namespace tron
{
// Class used to generate circular (or elliptic) cyclic movements.
// It extends from CyclicMovement.    
// Circular movements can have any orientation and positive or negative rotation (anti clockwise or clockwise respectively).
class CircularMovement : public CyclicMovement
{  
private: 
    bool brotation;                       // positive (anti clockwise) or negative (clockwise) rotation
    
public:  
    CircularMovement();
    //~CircularMovement();
    
    // create circular movement
    void createCircle(float freq, float amplitude, float angle, bool brotation); 
    // create elliptic movement
    void createEllipse(float freq, float amplitude, float relFactor, float angle, bool brotation); 
    
//    void updateRotation(bool brotation);    
    
private:
    void computePhases(bool brotation, float orientation);
};
}
#endif
