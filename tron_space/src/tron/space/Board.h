#ifndef __TRON_SPACE_BOARD_H
#define __TRON_SPACE_BOARD_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "tron/space/Space.h"

namespace tron
{
// Class representing a generic board, composed by spaces which can hold elements.
// It's state is automatically updated (empty, some filled or all-filled).
class Board
{
public:   
 enum eState
{
    eBOARD_EMPTY,                   // no spaces filled
    eBOARD_SOME_FILLED,         // some spaces filled
    eBOARD_ALL_FILLED             // all spaces filled
};

protected:
    int state;
    std::vector<Space> listSpaces;      // spaces of the board

public:
    Board();
    ~Board();
    
    int getState() {return state;};    
    std::vector<Space>& getSpaces() {return listSpaces;};
    int getNumSpaces() {return listSpaces.size();};    

    // add given space to board (ID assigned automatically)
    void addSpace(Space& oSpace);
    // get specified space (return nullptr if not exists))
    Space* getSpace(int pos);
    // updates board state (depending on spaces states)
    void checkState();

    // clean all board spaces 
    void clean();
    // clear board (eliminate all spaces)
    void clear();

    std::string toString();            
};

}  

#endif
