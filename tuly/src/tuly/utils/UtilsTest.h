#ifndef __TULY_UTILSTEST_H
#define __TULY_UTILSTEST_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <log4cxx/logger.h>

namespace tuly
{
// class used to conduct tests
class UtilsTest
{
 private:
     static log4cxx::LoggerPtr logger;

public:
//    UtilsTest();
//    ~UtilsTest();

    void testFileReader(std::string name);
    void testFileWriter();    
    
};

}    
#endif
