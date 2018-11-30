/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/space/SpaceCompare.h"

namespace tron
{
//SpaceCompare::SpaceCompare()
//{          
//}

SpaceCompare::~SpaceCompare ()
{
    listDifs.clear();
}

bool SpaceCompare::compareBoardStructures(Board& oBoard1, Board& oBoard2)
{
    // emulate structure comparison (to be really implemented when real structure assigned to boards)
    return (oBoard1.listSpaces.size() == oBoard2.listSpaces.size());    
}

bool SpaceCompare::compareBoardContents(Board& oBoard1, Board& oBoard2)
{
    // reset list of differences
    listDifs.clear();
    // compare individual spaces
    std::vector<Space>::iterator it = oBoard1.listSpaces.begin();
    std::vector<Space>::iterator end = oBoard1.listSpaces.end();
    std::vector<Space>::iterator it2 = oBoard2.listSpaces.begin();
    while (it != end)
    {
        // if spaces differ, add to list
        if (!(*it == *it2))
            listDifs.push_back(it->getID());
        it++;
        it2++;            
    }
    
    // return true if no differences
    return listDifs.empty();
}

}




