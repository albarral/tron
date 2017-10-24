#ifndef __TALKY2_ARMJOINTANGLES_H
#define __TALKY2_ARMJOINTANGLES_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "talky/coms/CommandBlock.h"

namespace talky2
{
// Class used to transfer data of an arm's joint (control and measured values).
// Uses talky language.
class ArmJointAngles
{    
   private:
        // arm joint angles
        float posHS;    
        float posVS;    
        float posEL;    
        float posHW;    
        float posVW;    

    public:
        // reset all values
        void reset();        
        // set pos values for each joint
        void setPosHS(float value) {posHS = value;}
        void setPosVS(float value) {posVS = value;}
        void setPosEL(float value) {posEL = value;}
        void setPosHW(float value) {posHW = value;}
        void setPosVW(float value) {posVW = value;}        
        // gets pos values from each joints
        float getPosHS() {return posHS;};        
        float getPosVS() {return posVS;};        
        float getPosEL() {return posEL;};        
        float getPosHW() {return posHW;};        
        float getPosVW() {return posVW;};                

        // check if specified object has same values
        bool isEqual(ArmJointAngles& oArmJointInfo);

        // reads joint positions from given command block
        bool readJointPositions(talky::CommandBlock& oCommandBlock);
        // writes joint positions to given command block
        bool writeJointPositions(talky::CommandBlock& oCommandBlock);
        
        // returns a description of the object
        std::string toString();        
};

}    
#endif
