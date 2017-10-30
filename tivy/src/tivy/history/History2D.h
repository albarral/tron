#ifndef __TIVY_HISTORY2D_H
#define __TIVY_HISTORY2D_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <deque>

#include "tivy/history/Click.h"

namespace tivy 
{
// record element
struct Record2D
{
    float signal1;   // signal value
    float signal2;   // signal value
    int etime;      // elapsed time (ms)    
};
    
// This class stores a history of records for a given time interval.
// It automatically deletes records older than this time.
class History2D
{
private:    
    // params
    int timeSpan;       // maximum age allowed for stored records (ms)
    // logic
    std::deque<Record2D> listRecords; // records list (deque used for FIFO & LIFO functionality)
    Click oClick;       // auxiliary clock
    int storedTime;    // accumulated stored time (of records in list)

public:
    History2D();       
    ~History2D();
    
    // set maximum allowed time for storage (ms)
    void setTimeSpan(int value) {timeSpan = value;};
    // reset the history
    void reset();
    // adds a new record
    void addRecord(float value1, float value2);
    // returns the records list
    std::deque<Record2D>& getListRecords() {return listRecords;};
        
private:    
    // deletes records older than time limit
    void purgeOld();
};
}    
#endif
