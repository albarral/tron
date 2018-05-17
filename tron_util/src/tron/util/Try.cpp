/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/Try.h"

namespace tron
{
Try::Try()
{
    reset();
}

void Try::reset()
{
    usage = 0;
    positives = 0;
    successRate = 0.0;    
}

void Try::update(bool bsuccess)
{
    // increase positives if success
    if (bsuccess)
        positives++;            
    // increase usage
    usage++;
    // compute success rate
    successRate = (float)positives / usage;
}
}
