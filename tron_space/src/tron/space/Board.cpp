/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <stdexcept>      // std::out_of_range

#include "tron/space/Board.h"

namespace tron
{
Board::Board()
{              
    state = Board::eBOARD_EMPTY;
}

Board::~Board ()
{
    clear();
}

void Board::addSpace(Space& oSpace)
{
    // automatic space ID assignment
    int pos = listSpaces.size();
    oSpace.setID(pos);
    listSpaces.push_back(oSpace);
}

Space* Board::getSpace(int pos)
{
    try
    {	
      return &(listSpaces.at(pos));
    }
    catch (const std::out_of_range& oor) 
    {
        return nullptr;
    }	
}

void Board::checkState()
{
    // special case: no spaces in board
    if (listSpaces.empty())
    {      
        state = Board::eBOARD_EMPTY;                       
        return;
    }        
    
    int numEmpty = 0;
    int numFilled = 0;
    // check spaces one by one
    for (Space& oSpace : listSpaces)
    {
        switch (oSpace.getState())
        {
            case Space::eSPACE_EMPTY: 
                numEmpty++;
                break;
            case Space::eSPACE_FILLED:
            case Space::eSPACE_MULTI_FILLED:
                numFilled++;
                break;
        }
    }
    
    // some spaces empty
    if (numEmpty > 0)
    {
        // some filled
        if (numFilled > 0)
            state = Board::eBOARD_SOME_FILLED;
        // none filled (= empty)
        else
            state = Board::eBOARD_EMPTY;                       
    }
    // no empty spaces (= all filled)
    else        
        state = Board::eBOARD_ALL_FILLED;
}

void Board::clean()
{
    for (Space& oSpace : listSpaces)
        oSpace.clear();   
    state = Board::eBOARD_EMPTY;
}

void Board::clear()
{
    listSpaces.clear();    
    state = Board::eBOARD_EMPTY;
}

std::string Board::toString()
{
    std::string text = "Board: state = " + std::to_string(state) + "]\n";
    for (Space& oSpace : listSpaces)
    {
        text += oSpace.toString() + "\n";        
    }
    
    return text;    
}

}




