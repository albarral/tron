#ifndef __TALKY2_ARMCLIENT_H
#define __TALKY2_ARMCLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/talky2/arm/ArmCommunicator.h"
#include "tron/robot/clients/TronArmClient.h"

namespace tron
{
// Arm client class (implementing TronArmClient interface) to control a robot arm.
class ArmClient : public ArmCommunicator, public TronArmClient
{    
private:
    std::string message;
        
public:
    ArmClient();
    //~ArmClient();

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
};

}
#endif
