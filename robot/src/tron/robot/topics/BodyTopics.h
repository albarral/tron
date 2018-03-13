#ifndef __TRON_ROBOT_BODYTOPICS_H
#define __TRON_ROBOT_BODYTOPICS_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/robot/topics/NodeTopics.h"

namespace tron
{
// Definition of body topics
 class BodyTopics : public NodeTopics
{
public:
    /*! body topics */
    enum eBodyTopics
    {
        eBODY_COMFORTABLE,            /*! comfortable category */
        eBODY_EXPRESSIVE,                /*! expressive category */
        eBODY_ARTISTIC,                     /*! artistic category */
        eBODY_EXTRA,                        /*! extra category */
        eBODY_DIM
    };

    /*! body topic names */
    static const std::string BODY_COMFORTABLE;
    static const std::string BODY_EXPRESSIVE;
    static const std::string BODY_ARTISTIC;
    static const std::string BODY_EXTRA;

 public:     
     BodyTopics();
     
protected:
     virtual void fillMap();
};
}
#endif
