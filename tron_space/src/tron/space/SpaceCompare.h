#ifndef __TRON_SPACE_SPACECOMPARE_H
#define __TRON_SPACE_SPACECOMPARE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "tron/space/Board.h"
#include "tron/space/Space.h"

namespace tron
{
// Class representing a board space, which can be filled with elements.    
class SpaceCompare
{
private:
    std::vector<int> listDifs;    // list of differences found in last comparison

public:
    //SpaceCompare();
    ~SpaceCompare();
        
    std::vector<int>& getListDifferences() {return listDifs;};
    
    // compare structures of given boards (return true if equal)
    bool compareBoardStructures(Board& oBoard1, Board& oBoard2);
    // compare contents of given boards (return true if equal), and informs the list of differences
    bool compareBoardContents(Board& oBoard1, Board& oBoard2);

    // compare contents of given spaces (return true if equal)
    bool compareSpaces(Space& oSpace1, Space& oSpace2);
};

}  

#endif
