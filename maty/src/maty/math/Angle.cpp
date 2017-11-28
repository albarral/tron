/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "maty/math/Angle.h"

namespace maty
{
float Angle::inLimits(float angle)
{
    // if too big angle, reduce it below 360
    if (angle > 360.0)
    {
        while (angle > 360.0)
            angle -= 360.0;
    }
    // if negative angle, increase it above 0
    else if (angle < 0.0)
    {
        while (angle < 0.0)
            angle += 360.0;
    }
        
    return angle;    
}

}
