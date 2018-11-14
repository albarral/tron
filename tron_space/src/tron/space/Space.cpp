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
}

Space::~Space ()
{
    clear();
}

void Space::setElements(std::list<int>& listElements2)
{
    listElements = listElements2;
}

void Space::addElement(int element)
{
    listElements.push_back(element);
}

bool Space::clearElement(int element)
{
    // search element in list
    auto it = std::find(listElements.begin(), listElements.end(), element);
    // if found, remove it
    if (it != listElements.end())
    {
        listElements.erase(it);
        return true;
    }
    else
        return false;    
}

bool Space::findElement(int element)
{
    // search element in list
    auto it = std::find(listElements.begin(), listElements.end(), element);
    return (it != listElements.end());
}

void Space::clear()
{
    listElements.clear();    
}

bool operator== (Space &s1, Space &s2)
{
    // fast check: both spaces empty
    if (s1.isEmpty() && s2.isEmpty())
        return true;
        
    // otherwise, if same number of elements
    if (s1.listElements.size() == s2.listElements.size())
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

std::string Space::toString()
{
    std::string text = "Space " + std::to_string(ID) + ":\t" ;
    for (int element : listElements)
        text += std::to_string(element) + ", ";        
    
    return text;    
}

}




