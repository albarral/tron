/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "TestTools.h"

using namespace log4cxx;

LoggerPtr TestTools::logger(Logger::getLogger("tron"));

// Constructor 
TestTools::TestTools()
{    
    modName = "TestTools";
 }

void TestTools::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    //testFileReading();
    testFileReading2();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestTools::testFileReading()
{
    LOG4CXX_INFO(logger, modName + ": testFileReading ...");
    
    std::string filename = "/home/albarral/coms/testfile.txt";
    std::ofstream outfilecleaner;
    std::ifstream infile;     
    std::ofstream outfile;     
    std::ofstream outfile2;     

    // first clean file
    outfilecleaner.open(filename, std::fstream::out | std::fstream::trunc);
    if (outfilecleaner.is_open())
        outfilecleaner.close();        
    
    infile.open(filename);     
    outfile.open(filename, std::fstream::out | std::fstream::app);
    outfile2.open(filename, std::fstream::out | std::fstream::app);
    if (!infile.is_open() || !outfile.is_open() || !outfile2.is_open())
    {
        LOG4CXX_ERROR(logger, modName + "files not opened");                        
        return;
    }
    
    writeBunch(outfile, 1);            
    readEverything(infile);        

    writeBunch(outfile2, 10);            
    readEverything(infile);

    writeBunch(outfile, 20);            
    readEverything(infile);

    readEverything(infile);
    
    if (infile.is_open())
        infile.close();    
    if (outfile.is_open())
        outfile.close();    
    if (outfile2.is_open())
        outfile2.close();    
}

void TestTools::writeBunch(std::ofstream& outfile, int i)
{
    std::string base = "hola";        

    for (int k = i; k < i+5; k++)
    {
        std::string line = base + std::to_string(k) + "\n";        
        outfile << line;                
    }
    outfile.flush();    
}

void TestTools::readEverything(std::ifstream& infile)
{
    LOG4CXX_INFO(logger, "read everything - pos " << infile.tellg());    
    std::string line;
    while (std::getline(infile, line))
    {
        LOG4CXX_INFO(logger, "read: " << line);   
    }
    
    refreshWhenEOF(infile);
}

void TestTools::refreshWhenEOF(std::ifstream& file)
{
    if (file.eof())
    {
        LOG4CXX_WARN(logger, "EOF -> file refreshed");                                
        file.clear();    
    }
}

void TestTools::testFileReading2()
{
    LOG4CXX_INFO(logger, modName + ": testFileReading2 ...");
    
    std::string filename = "/home/albarral/coms/testfile.txt";
    
    tron::FileReader oFileReader;
    tron::FileWriter oFileWriter;
    
    oFileReader.open(filename);
    // first clean file
    oFileReader.cleanFile();
    oFileWriter.open(filename, true);   // append mode
    
    
    if (!oFileReader.isOpen() || !oFileWriter.isOpen())
    {
        LOG4CXX_ERROR(logger, modName + "files not opened");                        
        return;
    }
    
    writeLines(oFileWriter, 1);            
    readLines(oFileReader);        

    writeLines(oFileWriter, 10);            
    readLines(oFileReader);        

    writeLines(oFileWriter, 20);            
    readLines(oFileReader);        

    readLines(oFileReader);        
    
    oFileReader.close();  
    oFileWriter.close();
}

void TestTools::writeLines(tron::FileWriter& oFileWriter, int i)
{
    std::string base = "hola";        

    for (int k = i; k < i+5; k++)
    {
        std::string line = base + std::to_string(k) + "\n";        
        oFileWriter.writeFlush(line);                
    }
}

void TestTools::readLines(tron::FileReader& oFileReader)
{
    LOG4CXX_INFO(logger, "read lines");    
    std::vector<std::string> listLines;
            
    if (oFileReader.readAllLines(listLines))
    {
        for (std::string line : listLines)
        {
            LOG4CXX_INFO(logger, "read: " << line);   
        }
    }
}
