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
    const std::string CAT_BODY_ARTISTIC = "art";  /*! artistic category */
    const std::string CAT_BODY_EXTRA = "extra";    /*! extra category */

    /*! expressive category */    
    const std::string EXPRESS_FEELING = "feel";      /*! set feeling to express (integer) */
    const std::string EXPRESS_HALT = "halt";          /*! halt expression */

    /*! artistic category */    
    const std::string ARTISTIC_FIGURE = "figure";             /*! id of artistic figure to implement (integer) */
    const std::string ARTISTIC_FREQ = "freq";                  /*! frequency of cyclic figure (Hz) */
    const std::string ARTISTIC_SIZE = "size";                   /*! size of cyclic figure (degrees) */
    const std::string ARTISTIC_ORIENTATION = "angle";     /*! orientation of cyclic figure (degrees) */
    const std::string ARTISTIC_RELFACTOR = "factor";       /*! relative xy factor of cyclic figure */
    const std::string ARTISTIC_HALT = "halt";                   /*! halt ongoing artistic movement */

    /*! extra category */
    const std::string EXTRA_BODY_END = "end";         /*! end body role process */

 public:    
    BodyLanguage(); 
    // builds language
    virtual void build();

 private:    
    // create category slangs
    void defineExpressiveCategory();
    void defineArtisticCategory();
    void defineExtraCategory();    
};
}
#endif
