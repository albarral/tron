#ifndef __TRON_TOPICS_NODE_H
#define __TRON_TOPICS_NODE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "tron/topics/NodeSection.h"
#include "tron/util/CodeMap.h"

namespace tron
{
// Base class for definition of node topics.
// A Node is composed by sections, which are composed by channels. Each channel will have a specific topic for communication.
 class Node
{        
 protected:
     int ID;                    
     std::string name;
     CodeMap oSectionsMap;  // node sections names map
     std::vector<NodeSection> listNodeSections; // list of node sections
     
 public:     
     Node(int id);
     ~Node();
     
     int getID() {return ID;}
     std::string getName() {return name;};

    // gets name for given section
    std::string getName4Section(int section);
    // gets code for given section name (returns -1 if unknown)
    int getSection4Name(std::string name);
     
    // get node section with given code
    NodeSection* getSection(int sectionCode);

    // return node description
    virtual std::string toString();    
};
}
#endif
