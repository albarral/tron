#ifndef __TRON_AI_SQUAD_H
#define __TRON_AI_SQUAD_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <list>

#include "tron/ai/Explorer.h"

namespace tron
{
// Dynamic squad of explorers, used for diagrams exploration.
class Squad
{
private:    
        std::list<Explorer> listExplorers;      // list of explorers
        int numBlocked;         // number of explorers blocked
        int numArrived;         // number of explorers that reached the target
        
public:
    Squad();
    ~Squad();

    std::list<Explorer>& getListExplorers() {return listExplorers;};
    int getNumExplorers() {return listExplorers.size();};
    int getNumBlocked() {return numBlocked;};
    int getNumArrived() {return numArrived;};
    
    // add given explorer to squad
    void addExplorer(Explorer& oExplorer);    
    // remove given explorer from squad
    void removeExplorer(std::list<Explorer>::iterator itExplorer);
    // recount blocked and arrived explorers
    void checkNumbers();     
};
}
#endif
