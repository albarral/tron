#ifndef __MATY_MATH_ARMPOLAR_H
#define __MATY_MATH_ARMPOLAR_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/ArmMath.h"

namespace maty
{
// Class used to compute an arm's polar positions (pan, tilt and radius).
// It must be tuned to the arm before using it.
class ArmPolar
{
private:
    float istPan;           // computed pan value (degrees)
    float istTilt;           // computed tilt value (degrees)
    float istRadius;      // computed radius value (cm)
    ArmMath oArmMath;   // utility class for arm computations

public:
        ArmPolar();
        //~ArmPolar();
                
       // tune sensor to arm sizes
       void tune(int lenHum, int lenRad);
       void getTuning(int& lenHumerus, int& lenRadius);               

       // compute polar positions
        void sense(float angleHS, float angleVS, float angleELB);

        float getPanAngle() {return istPan;}
        float getTiltAngle() {return istTilt;}
        float getRadius() {return istRadius;}
};
}
#endif
