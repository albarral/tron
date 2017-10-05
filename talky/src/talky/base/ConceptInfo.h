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
    int conceptId;                  // concept's id
    bool bneedsValue;           // flag indicating the concept is measurable (requires measure value when controlled, gives measure value when sensed)
};
}
#endif
