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
    numEmpty = 0;
    numFilled = 0;    
}

Board::~Board ()
{
    clear();
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

void Board::setSpaces(std::vector<Space>& listSpaces2)
{
    listSpaces = listSpaces2;
    // compute counters & update board state
    computeCounters();
    updateState();    
}

void Board::addSpace(Space& oSpace)
{
    // automatic space ID assignment
    int pos = listSpaces.size();
    oSpace.setID(pos);
    listSpaces.push_back(oSpace);

    // update counters & board state
    if (oSpace.isEmpty())
        numEmpty++;
    else
        numFilled++;
    updateState();    
}

void Board::updateSpace(int pos, Space& oSpace)
{
    try
    {	        
        bool bwasEmpty = oSpace.isEmpty();
        // copy space contents
        listSpaces.at(pos).setElements(oSpace.getElements());        
        
        // update counters if space state changed
        // empty -> filled
        if (bwasEmpty && !oSpace.isEmpty())
        {
            numEmpty--;
            numFilled++;
            // update board state
            updateState();    
        }
        // filled -> empty 
        else if (!bwasEmpty && oSpace.isEmpty())
        {
            numEmpty++;
            numFilled--;
            // update board state
            updateState();    
        }
    }
    // if pos out of range
    catch (const std::out_of_range& oor) 
    {
        return;
    }	    
}

void Board::updateState()
{
    // special case: no spaces in board
    if (listSpaces.empty())
    {      
        state = Board::eBOARD_EMPTY;                       
        return;
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

void Board::computeCounters()
{
    numEmpty = 0;
    numFilled = 0;
    // check spaces one by one
    for (Space& oSpace : listSpaces)
    {
        if (oSpace.isEmpty())
            numEmpty++;
        else
            numFilled++;
    }
}

void Board::clearContents()
{
    for (Space& oSpace : listSpaces)
        oSpace.clear();   

    // set counters & board state
    numEmpty = listSpaces.size();
    numFilled = 0;        
    state = Board::eBOARD_EMPTY;
}

void Board::clear()
{
    listSpaces.clear(); 
    // set counters & board state
    numEmpty = 0;
    numFilled = 0;        
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

bool operator!= (Board &b1, Board &b2)
{
    return !(b1 == b2);
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




