#ifndef __TRON_TOPICS_ROBOTNODES_H
#define __TRON_TOPICS_ROBOTNODES_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron
{
// Definition of robot nodes (and their names)
 class RobotNodes
{    
 public:     
    /*! robot nodes */
    enum eRobotNodes
    {
        eNODE_ARM,                  /*! arm node */
        eNODE_HAND,                /*! hand node */
        eNODE_VISION,              /*! vision node */
        eNODE_HEAD,                /*! head node */
        eNODE_WHEELS,            /*! wheels node */  
        eNODE_BODYROLE,        /*! body role node */  
        eNODE_DIM
    };
    // node names
    static const std::string ARM_NODE;         /*! arm node name */
    static const std::string HAND_NODE;        /*! hand node name */
    static const std::string VISION_NODE;      /*! vision node name */
    static const std::string HEAD_NODE;        /*! head node name */
    static const std::string WHEELS_NODE;    /*! wheels node name */
    static const std::string BODYROLE_NODE;    /*! body role node name */

 public:          
    // gets name for given node
    static std::string getName4Node(int node);
        
    // get nodes description
    static std::string toString();
};
}
#endif
