#ifndef __TRON_UTIL_SUPERGROUP_H
#define __TRON_UTIL_SUPERGROUP_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "tron/util/groups/Element.h"
#include "tron/util/groups/Group.h"

namespace tron
{
// Base class definition of a super group: a group whose elements are also groups.
// A super group is itself an element. 
class SuperGroup : public Element 
{
protected:
    std::vector<Group> listGroups; 

public:
    SuperGroup();
    SuperGroup(int id, std::string name);
    ~SuperGroup();
    
    void clear();
    void addGroup(Group& oGroup);
    std::vector<Group>& getGroups() {return listGroups;};
    int getNumGroups() {return listGroups.size();};    
    
    virtual std::string toString();    
};

}  

#endif
