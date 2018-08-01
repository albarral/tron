#ifndef __TRON_TOPICS_ROBOTNODES_H
#define __TRON_TOPICS_ROBOTNODES_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

#include "tron/util/CodeMap.h"

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
    
 private:    
    /*! names of robot nodes */
    const std::string ARM_NODE = "arm";    
    const std::string HAND_NODE = "hand";  
    const std::string VISION_NODE = "vision";
    const std::string HEAD_NODE = "head";    
    const std::string WHEELS_NODE = "wheels"; 
    const std::string BODYROLE_NODE = "body"; 
    CodeMap oNodesMap;  // map of robot nodes

 public:          
     RobotNodes();
     //~RobotNodes();
     
    // gets name for given node (returns empty if unknown)
    std::string getName4Node(int node);
    // gets code for given node name (returns -1 if unknown)
    int getNode4Name(std::string name);
        
    // get nodes description
    std::string toString();
};
}
#endif
