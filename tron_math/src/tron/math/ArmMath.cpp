/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <cmath>

#include "tron/math/ArmMath.h"
#include "tron/math/MathDefines.h"

namespace tron
{
// computes all the move steps in a movement
ArmMath::ArmMath()
{
    setLengths(20, 20);    // 20 cm default 
}

// update lengths and collateral values
void ArmMath::setLengths(int lenHum, int lenRad)
{
    if (lenHum>0)
        lenHumerus = lenHum;
    if (lenRad>0)
        lenRadius = lenRad;
    
    // compute collateral values
    sumSquares = lenHumerus*lenHumerus + lenRadius*lenRadius;
    doubleProduct = 2*lenHumerus*lenRadius;
    maxRadius = lenHumerus + lenRadius;
    minRadius = lenHumerus - lenRadius;
    if (minRadius < 0.0)
        minRadius = 0.0;
}

float ArmMath::computeRadius4ElbowAngle(float angleEL)
{
    // R² = lenH² + lenR² + 2*lenH*lenR*cos(EL)
    
    // convert to radians
    float radiansEL = angleEL * KPI_DIV_180;
    
    // radius computation
    return (sqrt(sumSquares + doubleProduct*cos(radiansEL)));
}

float ArmMath::computeTilt4JointAngles(float angleVS, float angleEL) 
{
    // b = lenH*cos(VS) + lenR*cos(VS+EL)
    // h = lenH*sin(VS)  + lenR*sin(VS+EL)
    // tan(tilt) = h/b
    
    // convert to radians
    float radiansVS = angleVS * KPI_DIV_180;
    float radians2 = (angleVS + angleEL) * KPI_DIV_180;
    // get base
    float b = lenHumerus * cos(radiansVS) + lenRadius * cos(radians2);
    // get height
    float h = lenHumerus * sin(radiansVS) + lenRadius * sin(radians2);
    
    // compute tilt angle & convert to degrees
    return (atan2(h, b) * K180_DIV_PI);
};

float ArmMath::computeElbowAngle4Radius(float radius)
{
    // cos(EL) = (R² - lenH² - lenR²) / 2*lenH*lenR  

    // to avoid limit radius to the valid range
    if (radius > maxRadius)
        radius = maxRadius;
    else if (radius < minRadius)
        radius = minRadius;
    
    // compute elbow angle & convert to degrees
    return (acos((radius*radius - sumSquares)/doubleProduct) * K180_DIV_PI);
}

}
