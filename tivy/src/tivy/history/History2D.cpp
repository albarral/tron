/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tivy/history/History2D.h"

namespace tivy 
{
History2D::History2D()
{
    reset();    
    timeSpan = 1000; // 1 second default storage
}

History2D::~History2D()
{
    reset();
}

void History2D::reset()
{
    listRecords.clear();
    storedTime = 0;
}

// add record to list
void History2D::addRecord(float value1, float value2)
{  
    // measure elapsed time
    oClick.read();
    oClick.start();
    
    // create record
    Record2D record = {value1, value2, oClick.getMillis()};    
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
void History2D::purgeOld()
{
    while (storedTime > timeSpan)
    {
        // get oldest record
        Record2D& record = listRecords.front();
        // discount its time
        storedTime -= record.etime;
        // and remove it from list
        listRecords.pop_front();        
    }        
}

}