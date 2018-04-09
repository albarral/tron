#ifndef __TRON_TEST_SIGNALS_H
#define __TRON_TEST_SIGNALS_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

// Class used to test tron_signals lib.
class TestSignals
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name

public:
    TestSignals();
    //~TestSignals();

    void makeTest();      
    
private:
    void testOscillators();
    void testDualOscillator();
};
#endif
