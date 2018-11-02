/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/diagram/Path.h"

namespace tron
{
Path::Path() 
{
    originState = endState = -1;
    overallCost = 0.0;
}


Path::~Path()
{
    listTransitions.clear();    
}

bool Path::addTransition(Transition& oTransition)
{
    // if transition starts at path end (or the path is empty)
    if (oTransition.getTransitionPk().getStateID() == endState || listTransitions.empty())
    {
        // set origin if first transition
        if (listTransitions.empty())
            originState = oTransition.getTransitionPk().getStateID();
        // append transition
        listTransitions.push_back(oTransition);
        // update cost
        overallCost += oTransition.getCost();
        // and update path end
        endState = oTransition.getEndStateID();
        return true;        
    }
    // otherwise it can't be added
    else
        return false;
}

bool Path::popLast()
{
    // if path not empty
    if (!listTransitions.empty())
    {
        // get last transition
        Transition& oTransition = listTransitions.back();
        // remove its cost
        overallCost -= oTransition.getCost();
        // set path end to its departure state
        endState = oTransition.getTransitionPk().getStateID();
        // and remove it from path
        listTransitions.pop_back();
        
        // if path totally deleted
        if (listTransitions.empty())        
            endState = -1;

        return true;        
    }
    // otherwise it can't be popped
    else
        return false;
}

bool Path::isConnected(Path& oPath2)
{
    // connected if it starts where this one ends
    return (oPath2.getOrigin() == endState);    
}

bool Path::add(Path& oPath2)
{
    // only add it if it starts on this path end 
    if (isConnected(oPath2))
    {
        // append transitions
        listTransitions.insert(listTransitions.end(), oPath2.getTransitions().begin(), oPath2.getTransitions().end());
        // update cost
        overallCost += oPath2.getOverallCost();
        // and update path end
        endState = oPath2.getEnd();
        return true;        
    }
    // otherwise it can't be added
    else
        return false;    
}

void Path::clear()
{
    listTransitions.clear();      
    originState = endState = 0;
    overallCost = 0.0;        
}

bool operator== (Path &p1, Path &p2)
{
    // if same origins, ends, cost and length
    if (p1.originState == p2.originState && 
            p1.endState == p2.endState && 
            p1.overallCost == p2.overallCost && 
            p1.listTransitions.size() == p2.listTransitions.size())
    {        
        // compare individual transitions
        std::vector<Transition>::iterator it1 = p1.listTransitions.begin();
        std::vector<Transition>::iterator it2 = p2.listTransitions.begin();
        std::vector<Transition>::iterator end1 = p1.listTransitions.end();
        bool bequal = true;        
        while (bequal && it1 != end1)
        {
            bequal = (it1->getTransitionPk() == it2->getTransitionPk());
            it1++;
            it2++;            
        }
        return bequal;
    }
    // otherwise, they are different
    else
        return false; 
}
 
bool operator!= (Path &p1, Path &p2)
{
    return !(p1 == p2);
}

std::string Path::toString()
{
    std::string text = "Path: origin = " + std::to_string(originState) + ", end = " + std::to_string(endState) + " , overallCost = " + std::to_string(overallCost) + "\n";
    for (Transition& oTransition : listTransitions)
    {
        text += oTransition.toString() + "\n";
    }        
        
    return text;
}

std::string Path::shortDesc()
{
    std::string text = "-";
    for (Transition& oTransition : listTransitions)
    {
        text += oTransition.getName() + ",";
    }        
        
    return text;
}

}