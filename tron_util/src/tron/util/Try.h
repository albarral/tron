#ifndef __TRON_UTIL_TRY_H
#define __TRON_UTIL_TRY_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
 
namespace tron
{
// Class used to track usage and success of a trial entity.
class Try
{    
private:
    int usage;  // number of tries
    int positives; // number of positives
    float successRate; // success rate [0, 1] 
    
public:  
    Try();
    
    int getUsage() {return usage;};
    float getSuccessRate() {return successRate;};
    
    void reset();
    void update(bool bsuccess);
};
}
#endif
