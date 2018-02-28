#ifndef __TRON_ROBOT_ARMSENSORS_H
#define __TRON_ROBOT_ARMSENSORS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

namespace tron
{
// Definition of arm sensor structures
    
struct JointsData
{
    float hs; 
    float vs; 
    float elb; 
    float hwri; 
    float vwri;   
};

struct JointsStates
{
    int hsState; 
    int vsState; 
    int elbState; 
    int hwriState; 
    int vwriState;   
};

struct AxesData
{
    float panPos; 
    float tiltPos; 
    float radialPos; 
};

struct AxesSpeeds
{
    float panSpeed; 
    float tiltSpeed; 
    float radialSpeed; 
};

}
#endif
