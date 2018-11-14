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
    eBOARD_FILLED,                   // some spaces filled
    eBOARD_ALL_FILLED             // all spaces filled
};

protected:
    int state;
    std::vector<Space> listSpaces;      // spaces of the board
    int numEmpty;           // empty spaces counter
    int numFilled;             // filled spaces counter 

public:
    Board();
    ~Board();
    
    int getState() {return state;};    
    std::vector<Space>& getSpaces() {return listSpaces;};
    int getNumSpaces() {return listSpaces.size();};    

    // get specified space (return nullptr if not exists))
    Space* getSpace(int pos);
    // set board spaces
    void setSpaces(std::vector<Space>& listSpaces2);
    // add given space to board (ID assigned automatically)
    void addSpace(Space& oSpace);
    // add given space to board (ID assigned automatically)
    void updateSpace(int pos, Space& oSpace);

    // clear board contents (deleting all space elements)
    void clearContents();
    // clear board structure (deleting all spaces)
    void clear();

    // compare board structure with given board (return true if structures are equal)
    bool compareStructure(Board& oBoard2);
    // compare board contents with given board (return true if contents are equal, informing list of differing spaces otherwise)
    bool compareContents(Board& oBoard2, std::vector<int>& listDifSpaces);

    // compare operator (return true if boards are equal)
    friend bool operator== (Board& b1, Board& b2);
    // difference operator (return true if boards are different)    
    friend bool operator!= (Board &b1, Board &b2);
        
    // get name of given state
    static std::string getStateName(int state);    
    std::string toString();            

private:
    // updates board state (depending on counters)
    void updateState();
    // compute empty and filled counters
    void computeCounters();

};

}  

#endif
