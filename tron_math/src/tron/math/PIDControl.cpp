/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/math/PIDControl.h"

namespace tron
{
PIDControl::PIDControl()
{
    // params default
    Kp = Ki = Kd = 0.0; 
    output = 0.0;
    error0 = 0.0;
}

void PIDControl::init(float kp, float ki, float kd)
{
    Kp = kp;
    Ki = ki;
    Kd = kd;
};

void PIDControl::reset()
{
    error0 = 0.0;
}

float PIDControl::control(float error)
{
    output = Kp*error + Kd*(error - error0);     // just PD control (I control pending)
    error0 = error;
    return output;
}

}