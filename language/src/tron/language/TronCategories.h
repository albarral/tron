#ifndef __TRON_LANGUAGE_CATEGORIES_H
#define __TRON_LANGUAGE_CATEGORIES_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

namespace tron
{
/** 
 * Class for definition of language categories.
 */
 class TronCategories
{
 public:     
    /*! language categories */
    enum eCategory
    {
        eCAT_OBJECTS,                /*! objects category */
        eCAT_ACTIONS,                /*! actions category */
        eCAT_FEATURES,             /*! features category */
        eCAT_DIM
    };

 public:         
//    TronThemes();              	
};
}
#endif
