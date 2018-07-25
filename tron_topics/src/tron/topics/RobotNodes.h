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
// A RobotSystem is a code map of nodes.
 class RobotNodes : public tron::CodeMap
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

 protected:
     int ID;
     std::string name;
     
 public:     
     RobotNodes(int id, std::string name);
     
     int getID() {return ID;}
     std::string getName() {return name;}
     
    // gets name for given node
    std::string getName4Node(int node);
    // gets code for given node name
    int getCode4Node(std::string nodeName);
        
    //  return system description
    virtual std::string toString();

 protected:
     virtual void fillNodes() = 0;
};
}
#endif
