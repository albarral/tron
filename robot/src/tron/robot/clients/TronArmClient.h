#ifndef __TRON_ROBOT_ARMCLIENT_H
#define __TRON_ROBOT_ARMCLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

namespace tron
{
// Interface class for arm clients
class TronArmClient
{        
 public:     
    // joint topic ...
    // set HS joint (horizontal shoulder) to given position (degrees)
    virtual bool setHS(float value) = 0;
    // set VS joint (vertical shoulder) to given position (degrees)
    virtual bool setVS(float value) = 0;
    // set ELB joint (elbow) to given position (degrees)
    virtual bool setELB(float value) = 0;
    // set HWRI joint (horizontal wrist) to given position (degrees)
    virtual bool setHWRI(float value) = 0;
    // set VWRI joint (vertical wrist) to given position (degrees)
    virtual bool setVWRI(float value) = 0;

    // axis topic ...
    // set pan axis to given position (degrees)
    virtual bool setPan(float value) = 0;
    // set tilt axis to given position (degrees)
    virtual bool setTilt(float value) = 0;
    // set radial axis to given position (cm)
    virtual bool setRadial(float value) = 0;
    // move pan axis at given speed (degrees/s)
    virtual bool setPanSpeed(float value) = 0;
    // move tilt axis at given speed (degrees/s)
    virtual bool setTiltSpeed(float value) = 0;
    // move radial axis at given speed (cm/s)
    virtual bool setRadialSpeed(float value) = 0;
    // keep arm tilt
    virtual bool keepTilt() = 0;
    
    // cyclic topic ...
    // set amplitude of frontal cycler first component (degrees)
    virtual bool setFrontCyclerAmp1(float value) = 0;
    // set angle of frontal cycler first component (degrees)
    virtual bool setFrontCyclerAngle1(float value) = 0;
    // set frequency of frontal cycler first component (Hz)
    virtual bool setFrontCyclerFreq1(float value) = 0;
    // set amplitude of frontal cycler second component (degrees)
    virtual bool setFrontCyclerAmp2(float value) = 0;
    // set angle of frontal cycler second component (degrees)
    virtual bool setFrontCyclerAngle2(float value) = 0;
    // set frequency of frontal cycler second component (Hz)
    virtual bool setFrontCyclerFreq2(float value) = 0;
    // set phase difference of frontal cycler components (degrees)
    virtual bool setFrontCyclerPhase(float value) = 0;
    // starts or stops frontal cycler movement
    virtual bool setFrontCyclerAction(int value) = 0;
};
}
#endif
