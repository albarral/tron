/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/topics/ArmTopic.h"
#include "talky/Topics.h"

namespace talky
{

ArmTopic::ArmTopic() 
{
    setTopic(Topics::eTOPIC_ARM);
}

void ArmTopic::build()
{
    reset();

    // create all arm topic categories
    createJointCategory();
    createAxisCategory();
    createCyclicCategory();
    createExtraCategory();
}

// create concepts of joint category
void ArmTopic::createJointCategory()
{
    int category = eCAT_ARM_JOINT;

    std::vector<ConceptInfo> listConcepts;
    
    ConceptInfo conceptInfo;
    conceptInfo.bneedsQuantity = true;    // same for all concepts in this category
    conceptInfo.id = eJOINT_HS_POS;
    listConcepts.push_back(conceptInfo);
    conceptInfo.id = eJOINT_VS_POS;
    listConcepts.push_back(conceptInfo);                         
    conceptInfo.id = eJOINT_ELB_POS;
    listConcepts.push_back(conceptInfo);                      
    conceptInfo.id = eJOINT_HWRI_POS;
    listConcepts.push_back(conceptInfo);                   
    conceptInfo.id = eJOINT_VWRI_POS;
    listConcepts.push_back(conceptInfo);                        

    addCategory(category, listConcepts);
}

// create concepts of axis category
void ArmTopic::createAxisCategory()
{
    int category = eCAT_ARM_AXIS;

    std::vector<ConceptInfo> listConcepts;

    ConceptInfo conceptInfo;
    conceptInfo.bneedsQuantity = true;    // same for all concepts in this category
    conceptInfo.id = eAXIS_PAN_POS;
    listConcepts.push_back(conceptInfo);                        
    conceptInfo.id = eAXIS_TILT_POS;
    listConcepts.push_back(conceptInfo);                        
    conceptInfo.id = eAXIS_RAD_POS;
    listConcepts.push_back(conceptInfo);                        
    conceptInfo.id = eAXIS_PAN_SPEED;
    listConcepts.push_back(conceptInfo);                        
    conceptInfo.id = eAXIS_TILT_SPEED;
    listConcepts.push_back(conceptInfo);                        
    conceptInfo.id = eAXIS_RAD_SPEED;
    listConcepts.push_back(conceptInfo);                        

    addCategory(category, listConcepts);
}

// create concepts of cyclic category
void ArmTopic::createCyclicCategory() 
{
    int category = eCAT_ARM_CYCLIC;

    std::vector<ConceptInfo> listConcepts;

    ConceptInfo concept;
    // FRONTAL CYCLER
    concept.id = eCYCLIC_FRONT_FREQ;
    concept.bneedsQuantity = true;  
    listConcepts.push_back(concept);                        
    concept.id = eCYCLIC_FRONT_AMP;
    concept.bneedsQuantity = true;  
    listConcepts.push_back(concept);                        
    concept.id = eCYCLIC_FRONT_ANGLE;
    concept.bneedsQuantity = true;  
    listConcepts.push_back(concept);                        
    concept.id = eCYCLIC_FRONT_START;
    concept.bneedsQuantity = false;  
    listConcepts.push_back(concept);                        
    concept.id = eCYCLIC_FRONT_STOP;
    concept.bneedsQuantity = false;  
    listConcepts.push_back(concept);                        
    // ARM MOVER
    concept.id = eCYCLIC_MOVER_TURN;
    concept.bneedsQuantity = true;  
    listConcepts.push_back(concept);                        
    concept.id = eCYCLIC_MOVER_WIDER;
    concept.bneedsQuantity = true;  
    listConcepts.push_back(concept);                        
    concept.id = eCYCLIC_MOVER_TALLER;
    concept.bneedsQuantity = true;  
    listConcepts.push_back(concept);                        
    concept.id = eCYCLIC_MOVER_FASTER;
    concept.bneedsQuantity = true;  
    listConcepts.push_back(concept);                        
    concept.id = eCYCLIC_MOVER_LAUNCH;
    concept.bneedsQuantity = false;  
    listConcepts.push_back(concept);                        
    concept.id = eCYCLIC_MOVER_STOP;
    concept.bneedsQuantity = false;  
    listConcepts.push_back(concept);                        

    addCategory(category, listConcepts);
}

// create concepts of extra category
void ArmTopic::createExtraCategory()
{
    int category = eCAT_ARM_EXTRA;

    std::vector<ConceptInfo> listConcepts;
    
    ConceptInfo concept;
    concept.bneedsQuantity = false;  // same for all concepts in this category
    concept.id = eEXTRA_ARM_STOP;
    listConcepts.push_back(concept);                        
    concept.id = eEXTRA_KEEP_TILT;
    listConcepts.push_back(concept);                        
    concept.id = eEXTRA_AMY_END;
    listConcepts.push_back(concept);                        

    addCategory(category, listConcepts);
}

}