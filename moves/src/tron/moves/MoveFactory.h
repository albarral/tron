#ifndef __TRON_MOVES_MOVEFACTORY_H
#define __TRON_MOVES_MOVEFACTORY_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/moves/CyclicMovement.h"

namespace tron
{
// Class used to compute complex cyclic movements.
class MoveFactory
{
private:    
    int figure;       // figure id (codes defined in tron::FiguresTheme class)
    float freq;         // frequency of cyclic movement
    float size;         // size of cyclic movement 
    float angle;        // orientation of cyclic movement (degrees)
    float relFactor;   // relative xy factor of cyclic movement
    float relFreq;      // relative frequency of wave movements
    bool brotation;     // rotation sign of circular movements (positive is anticlockwise)
    CyclicMovement* pCyclicMovement;

public:
    MoveFactory();
    ~MoveFactory();

    void setFreq(float value) {freq = value;}
    void setSize(float value) {size = value;}
    void setAngle(float value) {angle = value;}
    void setRelativeFactor(float value) {relFactor = value;}
    void setRelativeFreq(float value) {relFreq = value;}
    void setRotation(bool value) {brotation = value;}
    float getFreq() {return freq;}; 
    float getSize() {return size;}; 
    float getAngle() {return angle;}; 
    float getRelativeFactor() {return relFactor;};
    float getRelativeFreq() {return relFreq;};
    float getRotation() {return brotation;};

    CyclicMovement* getCyclicMovement() {return pCyclicMovement;};

    // generate cyclic movement for specified figure, returns false if unsupported figure
    bool generateMovement(int figure);        
};
}
#endif
