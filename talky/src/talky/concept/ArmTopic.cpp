/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/concept/ArmTopic.h"
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
    
    ConceptInfo concept;
    concept.bneedsValue = true;    // same for all concepts in this category
    concept.conceptId = eJOINT_HS_POS;
    listConcepts.push_back(concept);
    concept.conceptId = eJOINT_VS_POS;
    listConcepts.push_back(concept);                         
    concept.conceptId = eJOINT_ELB_POS;
    listConcepts.push_back(concept);                      
    concept.conceptId = eJOINT_HWRI_POS;
    listConcepts.push_back(concept);                   
    concept.conceptId = eJOINT_VWRI_POS;
    listConcepts.push_back(concept);                        

    addCategory(category, listConcepts);
}

// create concepts of axis category
void ArmTopic::createAxisCategory()
{
    int category = eCAT_ARM_AXIS;

    std::vector<ConceptInfo> listConcepts;

    ConceptInfo concept;
    concept.bneedsValue = true;    // same for all concepts in this category
    concept.conceptId = eAXIS_PAN_POS;
    listConcepts.push_back(concept);                        
    concept.conceptId = eAXIS_TILT_POS;
    listConcepts.push_back(concept);                        
    concept.conceptId = eAXIS_RAD_POS;
    listConcepts.push_back(concept);                        
    concept.conceptId = eAXIS_PAN_SPEED;
    listConcepts.push_back(concept);                        
    concept.conceptId = eAXIS_TILT_SPEED;
    listConcepts.push_back(concept);                        
    concept.conceptId = eAXIS_RAD_SPEED;
    listConcepts.push_back(concept);                        

    addCategory(category, listConcepts);
}

// create concepts of cyclic category
void ArmTopic::createCyclicCategory() 
{
    int category = eCAT_ARM_CYCLIC;

    std::vector<ConceptInfo> listConcepts;

    ConceptInfo concept;
    // FRONTAL CYCLER
    concept.conceptId = eCYCLIC_FRONT_FREQ;
    concept.bneedsValue = true;  
    listConcepts.push_back(concept);                        
    concept.conceptId = eCYCLIC_FRONT_AMP;
    concept.bneedsValue = true;  
    listConcepts.push_back(concept);                        
    concept.conceptId = eCYCLIC_FRONT_ANGLE;
    concept.bneedsValue = true;  
    listConcepts.push_back(concept);                        
    concept.conceptId = eCYCLIC_FRONT_START;
    concept.bneedsValue = false;  
    listConcepts.push_back(concept);                        
    concept.conceptId = eCYCLIC_FRONT_STOP;
    concept.bneedsValue = false;  
    listConcepts.push_back(concept);                        
    // ARM MOVER
    concept.conceptId = eCYCLIC_MOVER_TURN;
    concept.bneedsValue = true;  
    listConcepts.push_back(concept);                        
    concept.conceptId = eCYCLIC_MOVER_WIDER;
    concept.bneedsValue = true;  
    listConcepts.push_back(concept);                        
    concept.conceptId = eCYCLIC_MOVER_TALLER;
    concept.bneedsValue = true;  
    listConcepts.push_back(concept);                        
    concept.conceptId = eCYCLIC_MOVER_FASTER;
    concept.bneedsValue = true;  
    listConcepts.push_back(concept);                        
    concept.conceptId = eCYCLIC_MOVER_LAUNCH;
    concept.bneedsValue = false;  
    listConcepts.push_back(concept);                        
    concept.conceptId = eCYCLIC_MOVER_STOP;
    concept.bneedsValue = false;  
    listConcepts.push_back(concept);                        

    addCategory(category, listConcepts);
}

// create concepts of extra category
void ArmTopic::createExtraCategory()
{
    int category = eCAT_ARM_EXTRA;

    std::vector<ConceptInfo> listConcepts;
    
    ConceptInfo concept;
    concept.bneedsValue = false;  // same for all concepts in this category
    concept.conceptId = eEXTRA_ARM_STOP;
    listConcepts.push_back(concept);                        
    concept.conceptId = eEXTRA_KEEP_TILT;
    listConcepts.push_back(concept);                        
    concept.conceptId = eEXTRA_AMY_END;
    listConcepts.push_back(concept);                        

    addCategory(category, listConcepts);
}

}