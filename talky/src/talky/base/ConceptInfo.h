#ifndef __TALKY_CONCEPTINFO_H
#define __TALKY_CONCEPTINFO_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


namespace talky
{
/** 
 * Structure used to represent a concept
 */
struct ConceptInfo {
    int id;                  // concept's id
    bool bneedsQuantity;       // flag indicating the concept is measurable (needs quantity for being controlled & gives quantity when sensed)
};
}
#endif
