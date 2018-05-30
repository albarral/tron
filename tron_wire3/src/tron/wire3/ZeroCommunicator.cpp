/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   oriolorra@migtron.com   *
 ***************************************************************************/

#include <sys/stat.h>

#include "tron/wire3/ZeroCommunicator.h"

namespace tron
{
    
    ZeroCommunicator::ZeroCommunicator(){}

    void ZeroCommunicator::setPort(int node, int channel){
        port_ = 10000 + node + channel;
    }

}

