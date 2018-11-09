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
            case Board::eBOARD_EMPTY: 
                numEmpty++;
                break;
            case Board::eBOARD_FILLED:
            case Board::eBOARD_ALL_FILLED:
                numFilled++;
                break;
        }
    }
    
    // some spaces empty
    if (numEmpty > 0)
    {
        // some filled
        if (numFilled > 0)
            state = Board::eBOARD_FILLED;
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

bool operator== (Board& b1, Board& b2)
{
    // if same num spaces
    if (b1.listSpaces.size() == b2.listSpaces.size())
    {        
        // compare individual spaces
        std::vector<Space>::iterator it1 = b1.listSpaces.begin();
        std::vector<Space>::iterator it2 = b2.listSpaces.begin();
        std::vector<Space>::iterator end1 = b1.listSpaces.end();
        bool bequal = true;        
        while (bequal && it1 != end1)
        {
            bequal = (*it1 == *it2);
            it1++;
            it2++;            
        }
        return bequal;
    }
    // otherwise, they are different
    else
        return false; 
}

std::string Board::getStateName(int state)
{
    switch (state)
    {
        case Board::eBOARD_EMPTY: 
            return "empty";
        case Board::eBOARD_FILLED:
            return "filled";
        case Board::eBOARD_ALL_FILLED:
            return "all filled";
        default:
            return "undefined";        
    }
}

std::string Board::toString()
{
    std::string text = "Board: state = " + getStateName(state) + "\n";
    for (Space& oSpace : listSpaces)
    {
        text += oSpace.toString() + "\n";        
    }
    
    return text;    
}

}




