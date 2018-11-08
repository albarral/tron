/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <algorithm>

#include "tron/space/Space.h"

namespace tron
{
Space::Space(int id)
{          
    ID = id;
    state = Space::eSPACE_EMPTY;
}

Space::~Space ()
{
    clear();
}

void Space::addElement(int element)
{
    listElements.push_back(element);
    updateState();
}

bool Space::clearElement(int element)
{
    // search element in list
    auto it = std::find(listElements.begin(), listElements.end(), element);
    // if found, remove it
    if (it != listElements.end())
    {
        listElements.erase(it);
        updateState();
        return true;
    }
    else
        return false;    
}

bool Space::checkElementExists(int element)
{
    // search element in list
    auto it = std::find(listElements.begin(), listElements.end(), element);
    return (it != listElements.end());
}

void Space::clear()
{
    listElements.clear();    
    state = Space::eSPACE_EMPTY;
}

void Space::updateState()
{
    // no elements
    if (listElements.empty())
        state = Space::eSPACE_EMPTY;
    // one element
    else if (listElements.size() == 1)
        state = Space::eSPACE_FILLED;
    // various elements
    else
        state = Space::eSPACE_MULTI_FILLED;            
}

bool operator== (Space &s1, Space &s2)
{
    // if same state and num elements
    if (s1.state == s2.state &&             
       s1.listElements.size() == s2.listElements.size())
    {        
        // compare individual elements
        std::list<int>::iterator it1 = s1.listElements.begin();
        std::list<int>::iterator it2 = s2.listElements.begin();
        std::list<int>::iterator end1 = s1.listElements.end();
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

std::string Space::getStateName(int state)
{
    switch (state)
    {
        case Space::eSPACE_EMPTY: 
            return "empty";
        case Space::eSPACE_FILLED:
            return "filled";
        case Space::eSPACE_MULTI_FILLED:
            return "multifilled";
        default:
            return "undefined";        
    }
}

std::string Space::toString()
{
    std::string text = "Space " + std::to_string(ID) + ":\n" ;
    for (int element : listElements)
        text += std::to_string(element) + ", ";        
    
    return text;    
}

}




