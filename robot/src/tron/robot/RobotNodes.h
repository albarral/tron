#ifndef __TRON_ROBOT_NODES_H
#define __TRON_ROBOT_NODES_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tuly/utils2/CodeMap.h"

namespace tron
{
/** 
 * Class used to define robot nodes (and their standard names).
 */
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

    static const int NODE_ANY = 100;    /*! any node */  
    static const std::string ANY_NODE;  /*! any node name */
    
    // node names
    static const std::string ARM_NODE;         /*! arm node name */
    static const std::string HAND_NODE;        /*! hand node name */
    static const std::string VISION_NODE;      /*! vision node name */
    static const std::string HEAD_NODE;        /*! head node name */
    static const std::string WHEELS_NODE;    /*! wheels node name */
    static const std::string BODYROLE_NODE;    /*! body role node name */

 private:         
     tuly::CodeMap oNodesMap;                      /*! code map for robot nodes */    

 public:         
    RobotNodes();              	
     
    // gets name for given node code
    std::string getName4Node(int node);
    // gets code for given node name
    int getCode4Node(std::string nodeName);
    
    std::string getMapDescription();
};
}
#endif
