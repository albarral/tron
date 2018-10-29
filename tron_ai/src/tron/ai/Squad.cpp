/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/ai/Squad.h"

namespace tron
{
Squad::Squad() 
{
    numBlocked = numArrived = 0;
}

Squad::~Squad()
{
    listExplorers.clear();
}

void Squad::addExplorer(Explorer& oExplorer)
{
    listExplorers.push_back(oExplorer);    
}

void Squad::removeExplorer(std::list<Explorer>::iterator itExplorer)
{
    listExplorers.erase(itExplorer);
}

void Squad::checkNumbers()
{
    numBlocked = numArrived = 0;
    
    for (Explorer& oExplorer : listExplorers)
    {
        if (oExplorer.isBlocked())
            numBlocked++;
        else if (oExplorer.isArrived())
            numArrived++;            
    }
}

}