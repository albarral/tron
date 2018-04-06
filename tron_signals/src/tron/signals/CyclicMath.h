#ifndef __TRON_SIGNALS_CYCLICMATH_H
#define __TRON_SIGNALS_CYCLICMATH_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

namespace tron
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
