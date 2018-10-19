#ifndef __TRON_AI_PATHFINDER_H
#define __TRON_AI_PATHFINDER_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <log4cxx/logger.h>

#include "tron/diagram/Diagram.h"
#include "tron/diagram/Path.h"

namespace tron
{
// Utility class used for finding paths in state diagrams.
class PathFinder
{
private:
        static log4cxx::LoggerPtr logger;
        
public:
        //PathFinder();
        //~PathFinder();
    
    // find an aleatory path (in given diagram) of given length from state1
    static Path findAleatoryPath(Diagram& oDiagram, int state1, int length);

    // find the shortest path (in given diagram) from state1 to state2
    //static Path findShortestPath(Diagram& oDiagram, int state1, int state2);
    
private:
//        void informChangeDetected();
};
}
#endif
