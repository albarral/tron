/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/math/ArmPolar.h"

namespace tron
{
ArmPolar::ArmPolar()
{
    istPan = 0.0;         
    istTilt = 0.0;    
    istRadius = 0.0;
}

void ArmPolar::tune(int lenHum, int lenRadius)
{
    oArmMath.setLengths(lenHum, lenRadius);
}

void ArmPolar::getTuning(int& lenHumerus, int& lenRadius)
{
    lenHumerus = oArmMath.getLenHumerus();
    lenRadius = oArmMath.getLenRadius();    
}

void ArmPolar::sense(float angleHS, float angleVS, float angleELB)
{
    istPan = angleHS;
    istTilt = oArmMath.computeTilt4JointAngles(angleVS, angleELB);      
    istRadius = oArmMath.computeRadius4ElbowAngle(angleELB);
}
}