#ifndef __TALKY_BODYLANGUAGE_H
#define __TALKY_BODYLANGUAGE_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "talky/base/Language.h"

namespace talky
{
// Class defining the language for the body role topic.
 class BodyLanguage: public Language
{
 public:
    /*! body categories */
    const std::string CAT_BODY_EXPRESSIVE = "express";    /*! expressive category */
    const std::string CAT_BODY_ARMMOVER = "amover";  /*! arm mover category */
    const std::string CAT_BODY_EXTRA = "extra";    /*! extra category */

    /*! expressive category */    
    const std::string EXPRESS_FEELING = "feel";      /*! set feeling to express (integer) */
    const std::string EXPRESS_HALT = "halt";          /*! halt expression */

    /*! arm mover category */    
    const std::string ARMMOVER_TYPE = "type";             /*! set movement type (integer) */
    const std::string ARMMOVER_ACTION = "go";          /*! start/stop movement (boolean) */
    const std::string ARMMOVER_TURN = "turn";             /*! change movement orientation (degrees) */
    const std::string ARMMOVER_WIDER = "wider";            /*! change movement width (boolean) */
    const std::string ARMMOVER_TALLER = "taller";           /*! change movement height (boolean) */
    const std::string ARMMOVER_FASTER = "faster";           /*! change movement speed (boolean) */

    /*! extra category */
    const std::string EXTRA_BODY_END = "end";         /*! end body role process */

 public:    
    BodyLanguage(); 
    // builds language
    virtual void build();

 private:    
    // create category slangs
    void defineExpressiveCategory();
    void defineArmMoverCategory();
    void defineExtraCategory();    
};
}
#endif
