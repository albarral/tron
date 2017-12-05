/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/languages/BodyLanguage.h"
#include "talky/base/Slang.h"
#include "talky/topics/BodyTopic.h"
#include "talky/Topics.h"

namespace talky
{

BodyLanguage::BodyLanguage() 
{
}

void BodyLanguage::build()
{
    reset();

    // set body role topic
    setTopic(Topics::eTOPIC_BODYROLE);
    // define categories
    defineExpressiveCategory();
    defineArtisticCategory();
    defineExtraCategory();
}

// create slang for expressive category
void BodyLanguage::defineExpressiveCategory()
{
    int category = BodyTopic::eCAT_BODY_EXPRESSIVE;
    addCategory(category, BodyLanguage::CAT_BODY_EXPRESSIVE);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(BodyTopic::eEXPRESS_FEELING, BodyLanguage::EXPRESS_FEELING);                        
    oSlang.addWord(BodyTopic::eEXPRESS_HALT, BodyLanguage::EXPRESS_HALT);                        
    addSlang(category, oSlang);    
}

// create slang for arm mover category
void BodyLanguage::defineArtisticCategory()
{
    int category = BodyTopic::eCAT_BODY_ARTISTIC;
    addCategory(category, BodyLanguage::CAT_BODY_ARTISTIC);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(BodyTopic::eARTISTIC_FIGURE, BodyLanguage::ARTISTIC_FIGURE);                        
    oSlang.addWord(BodyTopic::eARTISTIC_FREQ, BodyLanguage::ARTISTIC_FREQ);                        
    oSlang.addWord(BodyTopic::eARTISTIC_SIZE, BodyLanguage::ARTISTIC_SIZE);                        
    oSlang.addWord(BodyTopic::eARTISTIC_ORIENTATION, BodyLanguage::ARTISTIC_ORIENTATION);                        
    oSlang.addWord(BodyTopic::eARTISTIC_RELFACTOR, BodyLanguage::ARTISTIC_RELFACTOR);                        
    oSlang.addWord(BodyTopic::eARTISTIC_HALT, BodyLanguage::ARTISTIC_HALT);                        
    addSlang(category, oSlang);    
}


// create slang for extra category
void BodyLanguage::defineExtraCategory()
{
    int category = BodyTopic::eCAT_BODY_EXTRA;
    addCategory(category, BodyLanguage::CAT_BODY_EXTRA);

    Slang oSlang;    
    oSlang.setCategory(category);
    oSlang.addWord(BodyTopic::eEXTRA_BODY_END, BodyLanguage::EXTRA_BODY_END);                      
    addSlang(category, oSlang);    
}

}