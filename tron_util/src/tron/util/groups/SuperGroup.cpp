/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/groups/SuperGroup.h"

namespace tron
{
SuperGroup::SuperGroup() : SuperGroup(-1, "", -1)
{          
}

SuperGroup::SuperGroup(int id) : SuperGroup(id, "", -1)
{          
}

SuperGroup::SuperGroup(int id, std::string name) : SuperGroup(id, name, -1)
{          
}

SuperGroup::SuperGroup(int id, std::string name, int nature) : Element(id, name, nature)
{          
    type = Element::eTYPE_SUPERGROUP;
}

SuperGroup::~SuperGroup ()
{
    clear();
}

void SuperGroup::clear()
{
    listGroups.clear();    
}

void SuperGroup::addGroup(Group& oGroup)
{
    // when adding a group to the super group, set the super group id for the group
    oGroup.setGroup(id);
    listGroups.push_back(oGroup);
}

std::string SuperGroup::toString()
{
    std::string text = "SuperGroup [" + Element::toString() + "]\n";
    for (Group& oGroup : listGroups)
    {
        text += oGroup.toString() + "\n";        
    }
    
    return text;    
}

}




