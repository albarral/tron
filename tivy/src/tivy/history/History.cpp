/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tivy/history/History.h"

namespace tivy 
{
History::History()
{
    reset();    
    timeSpan = 1000; // 1 second default storage
}

History::~History()
{
    reset();
}

void History::reset()
{
    listRecords.clear();
    storedTime = 0;
}

// add record to list
void History::addRecord(float value)
{  
    // measure elapsed time
    oClick.read();
    oClick.start();
    
    // create record
    Record record = {value, oClick.getMillis()};    
    // if first record, no elapsed time
    if (listRecords.empty())
        record.etime = 0;

    // add it to list
    listRecords.push_back(record);       
    // and update the stored time
    storedTime += record.etime;
    
    // finally purge old records
    purgeOld();
}

 // deletes records older than time limit
void History::purgeOld()
{
    while (storedTime > timeSpan)
    {
        // get oldest record
        Record& record = listRecords.front();
        // discount its time
        storedTime -= record.etime;
        // and remove it from list
        listRecords.pop_front();        
    }        
}

}