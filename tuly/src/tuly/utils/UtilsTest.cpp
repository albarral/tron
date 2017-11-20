/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

//#include <cstdlib>  // for getenv

#include <log4cxx/logger.h>

#include "tuly/utils/UtilsTest.h"
#include "tuly/utils/FileReader.h"
#include "tuly/utils/FileWriter.h"

using namespace log4cxx;

namespace tuly
{
LoggerPtr UtilsTest::logger(Logger::getLogger("amy.utils"));    


void UtilsTest::testFileReader(std::string name)
{
    FileReader oFileReader;
    
    if (oFileReader.open(name))        
    {
         LOG4CXX_INFO(logger, "Read start");
         std::string line;
         do 
         {
             line = oFileReader.readLine();
             LOG4CXX_INFO(logger, line);             
         }
         while (!line.empty());         

         oFileReader.close();
         LOG4CXX_INFO(logger, "Read end");
    }
    else
     LOG4CXX_ERROR(logger, "Can't open file " << name);
}

void UtilsTest::testFileWriter()
{       
//    char* pVar = getenv("HOME");
//    
//    if (pVar==NULL)
//     LOG4CXX_ERROR(logger, "Test failed: HOME var not found");
//        
//    std::string name(pVar);
//    name = name + "/TESTS/testFile.txt";
    
    FileWriter oFileWriter;
    std::string name = "test.txt";
    testFileReader(name);
    if (oFileWriter.open(name, true))        
    {
         LOG4CXX_INFO(logger, "write start")                 
        std::string line = " frase de prueba\n";
        oFileWriter.writeFlush(line);
        testFileReader(name);

        //oFile.goTop();
        std::string line2 = " frase de prueba2\n";
        oFileWriter.writeFlush(line2);
        testFileReader(name);

        std::string line3 = " frase de prueba3\n";
        oFileWriter.writeFlush(line3);
        testFileReader(name);
        LOG4CXX_INFO(logger, "write end");
        oFileWriter.close();
    }
    else
     LOG4CXX_ERROR(logger, "Test failed: unable to open file " << name);
}


}