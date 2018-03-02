#ifndef __TALKY2_ARMCLIENT_H
#define __TALKY2_ARMCLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/talky2/arm/ArmChannelClient.h"
#include "tron/robot/clients/TronArmClient.h"

namespace tron
{
// Arm client class (implementing TronArmClient interface) to control a robot arm.
class ArmClient : public TronArmClient
{    
private:
    static log4cxx::LoggerPtr logger;
    ArmChannelClient* pArmJointClient;
    ArmChannelClient* pArmAxisClient;
    ArmChannelClient* pArmCyclicClient;
    ArmChannelClient* pArmExtraClient;
        
public:
    ArmClient();
    ~ArmClient();

    // set HS joint (horizontal shoulder) to given position (degrees)
    virtual bool setHS(float value);
    // set VS joint (vertical shoulder) to given position (degrees)
    virtual bool setVS(float value);
    // set ELB joint (elbow) to given position (degrees)
    virtual bool setELB(float value);
    // set HWRI joint (horizontal wrist) to given position (degrees)
    virtual bool setHWRI(float value);
    // set VWRI joint (vertical wrist) to given position (degrees)
    virtual bool setVWRI(float value);    
    
    // axis topic ...
    // set pan axis to given position (degrees)
    virtual bool setPan(float value);
    // set tilt axis to given position (degrees)
    virtual bool setTilt(float value);
    // set radial axis to given position (cm)
    virtual bool setRadial(float value);
    // move pan axis at given speed (degrees/s)
    virtual bool setPanSpeed(float value);
    // move tilt axis at given speed (degrees/s)
    virtual bool setTiltSpeed(float value);
    // move radial axis at given speed (cm/s)
    virtual bool setRadialSpeed(float value);

    // cyclic topic ...
    // set amplitude of frontal cycler first component (degrees)
    virtual bool setFrontCyclerAmp1(float value);
    // set angle of frontal cycler first component (degrees)
    virtual bool setFrontCyclerAngle1(float value);
    // set frequency of frontal cycler first component (Hz)
    virtual bool setFrontCyclerFreq1(float value);
    // set amplitude of frontal cycler second component (degrees)
    virtual bool setFrontCyclerAmp2(float value);
    // set angle of frontal cycler second component (degrees)
    virtual bool setFrontCyclerAngle2(float value);
    // set frequency of frontal cycler second component (Hz)
    virtual bool setFrontCyclerFreq2(float value);
    // set phase difference of frontal cycler components (degrees)
    virtual bool setFrontCyclerPhase(float value);

    // extra topic ...    
    // stop arm
    virtual bool stopArm();
    // keep arm tilt
    virtual bool keepTilt();
    // end arm control process
    virtual bool endArm();            
};

}
#endif
