/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky2/arm/ArmJointAngles.h"

#include "talky/Topics.h"
#include "talky/coms/Command.h"
#include "talky/topics/ArmTopic.h"

namespace talky2
{
void ArmJointAngles::reset()
{
    posHS = 0;
    posVS = 0;
    posEL = 0;
    posHW = 0;
    posVW = 0;
}


bool ArmJointAngles::isEqual(ArmJointAngles& oArmJointInfo)
{
    return ((posHS == oArmJointInfo.posHS) &&
                (posVS == oArmJointInfo.posVS) &&
                (posEL == oArmJointInfo.posEL) &&
                (posHW == oArmJointInfo.posHW) &&
                (posVW == oArmJointInfo.posVW));
}

bool ArmJointAngles::readJointPositions(talky::CommandBlock& oCommandBlock)
{            
    bool ballOK = true;
    // analyze each command in the block
    for (talky::Command& oCommand : oCommandBlock.getListCommands())
    {
        // if not arm topic and joint category, skip read
        if (oCommand.getTopic() != talky::Topics::eTOPIC_ARM || oCommand.getCategory() != talky::ArmTopic::eCAT_ARM_JOINT)
        {
            ballOK = false;
            break;
        }
        
        float quantity = oCommand.getQuantity();
        switch (oCommand.getConcept())
        {
            case talky::ArmTopic::eJOINT_HS_POS:
                posHS = quantity;
                break;
            case talky::ArmTopic::eJOINT_VS_POS:
                posVS = quantity;
                break;
            case talky::ArmTopic::eJOINT_ELB_POS:
                posEL = quantity;
                break;
            case talky::ArmTopic::eJOINT_HWRI_POS:
                posHW = quantity;
                break;
            case talky::ArmTopic::eJOINT_VWRI_POS:
                posVW = quantity;
                break;
        }            
    }
    
    return ballOK;
}

bool ArmJointAngles::writeJointPositions(talky::CommandBlock& oCommandBlock)
{
    // all commands in the block have arm topic and joint category
    talky::Command oCommand;        
    oCommand.setTopic(talky::Topics::eTOPIC_ARM);
    oCommand.setCategory(talky::ArmTopic::eCAT_ARM_JOINT);
       
    // create a talky command for each joint and add it to given command block
    // HS
    oCommand.setConcept(talky::ArmTopic::eJOINT_HS_POS);
    oCommand.setQuantity(posHS);
    oCommandBlock.addCommand(oCommand);
    // VS
    oCommand.setConcept(talky::ArmTopic::eJOINT_VS_POS);
    oCommand.setQuantity(posVS);
    oCommandBlock.addCommand(oCommand);
    // ELB
    oCommand.setConcept(talky::ArmTopic::eJOINT_ELB_POS);
    oCommand.setQuantity(posEL);
    oCommandBlock.addCommand(oCommand);
    // HWRI
    oCommand.setConcept(talky::ArmTopic::eJOINT_HWRI_POS);
    oCommand.setQuantity(posHW);
    oCommandBlock.addCommand(oCommand);
    // VWRI
    oCommand.setConcept(talky::ArmTopic::eJOINT_VWRI_POS);
    oCommand.setQuantity(posVW);
    oCommandBlock.addCommand(oCommand);

    return true;
}

std::string ArmJointAngles::toString()
{
    std::string desc = "[ArmJointAngles]: \n posHS = " + std::to_string(posHS) + 
                             "\n posVS = " + std::to_string(posVS) +
                             "\n posEL = " + std::to_string(posEL) +
                             "\n posHW = " + std::to_string(posHW) +
                             "\n posVW = " + std::to_string(posVW);
    
    return desc;
}

}
