/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/languages/ArmLanguage.h"
#include "talky/base/Slang.h"
#include "talky/topics/ArmTopic.h"
#include "talky/Topics.h"

namespace talky
{

ArmLanguage::ArmLanguage() 
{
}

void ArmLanguage::build()
{
    reset();

    // set arm topic
    setTopic(Topics::eTOPIC_ARM);
    // define all arm topic categories
    defineJointCategory();
    defineAxisCategory();
    defineCyclicCategory();
    defineExtraCategory();
}

// create slang for joint category
void ArmLanguage::defineJointCategory()
{
    int category = ArmTopic::eCAT_ARM_JOINT;
    addCategory(category, CAT_ARM_JOINT);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(ArmTopic::eJOINT_HS_POS, JOINT_HS_POS);
    oSlang.addWord(ArmTopic::eJOINT_VS_POS, JOINT_VS_POS);                         
    oSlang.addWord(ArmTopic::eJOINT_ELB_POS, JOINT_ELB_POS);                      
    oSlang.addWord(ArmTopic::eJOINT_HWRI_POS, JOINT_HWRI_POS);                   
    oSlang.addWord(ArmTopic::eJOINT_VWRI_POS, JOINT_VWRI_POS);                        
    oSlang.addWord(ArmTopic::eJOINT_HS_STATE, JOINT_HS_STATE);
    oSlang.addWord(ArmTopic::eJOINT_VS_STATE, JOINT_VS_STATE);                         
    oSlang.addWord(ArmTopic::eJOINT_ELB_STATE, JOINT_ELB_STATE);                      
    oSlang.addWord(ArmTopic::eJOINT_HWRI_STATE, JOINT_HWRI_STATE);                   
    oSlang.addWord(ArmTopic::eJOINT_VWRI_STATE, JOINT_VWRI_STATE);                        
    addSlang(category, oSlang);    
}

// create slang for axis category
void ArmLanguage::defineAxisCategory()
{
    int category = ArmTopic::eCAT_ARM_AXIS;
    addCategory(category, CAT_ARM_AXIS);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(ArmTopic::eAXIS_PAN_POS, AXIS_PAN_POS);
    oSlang.addWord(ArmTopic::eAXIS_TILT_POS, AXIS_TILT_POS);                         
    oSlang.addWord(ArmTopic::eAXIS_RAD_POS, AXIS_RAD_POS);                      
    oSlang.addWord(ArmTopic::eAXIS_PAN_SPEED, AXIS_PAN_SPEED);                   
    oSlang.addWord(ArmTopic::eAXIS_TILT_SPEED, AXIS_TILT_SPEED);                        
    oSlang.addWord(ArmTopic::eAXIS_RAD_SPEED, AXIS_RAD_SPEED);                        
    addSlang(category, oSlang);    
}

// create slang for cyclic category
void ArmLanguage::defineCyclicCategory() 
{
    int category = ArmTopic::eCAT_ARM_CYCLIC;
    addCategory(category, CAT_ARM_CYCLIC);

    Slang oSlang;    
    oSlang.setCategory(category);
    // FRONTAL CYCLER
    oSlang.addWord(ArmTopic::eCYCLIC_FRONT1_FREQ, CYCLIC_FRONT1_FREQ);
    oSlang.addWord(ArmTopic::eCYCLIC_FRONT1_AMP, CYCLIC_FRONT1_AMP);                         
    oSlang.addWord(ArmTopic::eCYCLIC_FRONT1_ANGLE, CYCLIC_FRONT1_ANGLE);                      
    oSlang.addWord(ArmTopic::eCYCLIC_FRONT2_FREQ, CYCLIC_FRONT2_FREQ);
    oSlang.addWord(ArmTopic::eCYCLIC_FRONT2_AMP, CYCLIC_FRONT2_AMP);                         
    oSlang.addWord(ArmTopic::eCYCLIC_FRONT2_ANGLE, CYCLIC_FRONT2_ANGLE);                      
    oSlang.addWord(ArmTopic::eCYCLIC_FRONT_START, CYCLIC_FRONT_START);                   
    oSlang.addWord(ArmTopic::eCYCLIC_FRONT_STOP, CYCLIC_FRONT_STOP);                        
    addSlang(category, oSlang);    
}

// create slang for extra category
void ArmLanguage::defineExtraCategory()
{
    int category = ArmTopic::eCAT_ARM_EXTRA;
    addCategory(category, CAT_ARM_EXTRA);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(ArmTopic::eEXTRA_ARM_STOP, EXTRA_ARM_STOP);
    oSlang.addWord(ArmTopic::eEXTRA_KEEP_TILT, EXTRA_KEEP_TILT);                         
    oSlang.addWord(ArmTopic::eEXTRA_AMY_END, EXTRA_AMY_END);                      
    addSlang(category, oSlang);    
}

}