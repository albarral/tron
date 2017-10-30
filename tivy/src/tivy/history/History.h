#ifndef __TIVY_HISTORY_H
#define __TIVY_HISTORY_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <deque>

#include "tivy/history/Click.h"

namespace tivy 
{
// record element
struct Record
{
    float signal;   // signal value
    int etime;      // elapsed time (ms)    
};
    
// This class stores a history of records for a given time interval.
// It automatically deletes records older than this time.
class History
{
private:    
    // params
    int timeSpan;       // maximum age allowed for stored records (ms)
    // logic
    std::deque<Record> listRecords; // records list (deque used for FIFO & LIFO functionality)
    Click oClick;       // auxiliary clock
    int storedTime;    // accumulated stored time (of records in list)

public:
    History();       
    ~History();
    
    // set maximum allowed time for storage (ms)
    void setTimeSpan(int value) {timeSpan = value;};
    // reset the history
    void reset();
    // adds a new record
    void addRecord(float value);
    // returns the records list
    std::deque<Record>& getListRecords() {return listRecords;};
        
private:    
    // deletes records older than time limit
    void purgeOld();
};
}    
#endif
