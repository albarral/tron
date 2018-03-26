#ifndef __MATY_MATH_CYCLICMATH_H
#define __MATY_MATH_CYCLICMATH_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

namespace maty
{
// Class used to compute cyclic movements.
class CyclicMath
{
public:
    //CyclicMath();
    //~CyclicMath();                

    static float getTriangularSpeed4Movement(float freq, float amp);
};
}
#endif
