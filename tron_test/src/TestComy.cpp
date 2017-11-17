/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestComy.h"
#include "comy/file/ComyFileClient.h"
#include "comy/file/ComyFilePublisher.h"
#include "comy/file/ComyFileSubscriber.h"

using namespace log4cxx;

LoggerPtr TestComy::logger(Logger::getLogger("tron"));

// Constructor 
TestComy::TestComy()
{    
    modName = "TestComy";
 }

void TestComy::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    //testComsClientServer();
    //testComsPublishSubscribe();       
    testFileReading2();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestComy::testComsClientServer()
{
    LOG4CXX_INFO(logger, modName + ": testComsClientServer ...");
    
    comy::ComyFileClient oComyClient;
    comy::ComyFileServer oComyServer;
    
    // connection
    // multichannel communication
    std::string topic = "topic";
    std::string category = "cat";
    oComyClient.connect(topic, category);
    oComyServer.connect(topic, category);
    
    if (!oComyClient.isConnected() || !oComyServer.isConnected())
    {
        LOG4CXX_ERROR(logger, modName + ": client or server not connected. Exit test!");                        
        return;
    }
    
    // send message 1
    std::string msg = "hola, que tal?";            
    oComyClient.sendMessage(msg);
    LOG4CXX_INFO(logger, modName + ": message sent ... " + msg);                

    // receive message
    readByServer(oComyServer);

    // send message 2
    msg = "yo muy bien";            
    oComyClient.sendMessage(msg);
    LOG4CXX_INFO(logger, modName + ": message sent ... " + msg);                

    // receive message
    readByServer(oComyServer);
}


void TestComy::testFileReading()
{
    LOG4CXX_INFO(logger, modName + ": testFileReading ...");
    
    std::string filename = "/home/albarral/coms/testfile.txt";
    std::fstream file;     

    bool bok;     
    file.open(filename, std::fstream::in);
        
    bok = (file.is_open());
    
    if (!bok)
    {
        LOG4CXX_ERROR(logger, modName + "file not opened");                        
        return;
    }
    
    int maxIterations = 30;
    int pos = 0;
    for (int i = 0; i < maxIterations; i++)
    {
        LOG4CXX_INFO(logger, "i = " << i);    
        // check safe reading
        bok = safeRead(file, pos);
        LOG4CXX_INFO(logger, "check " << bok);    
        // if safe, advance position
        if (bok)
        {
            pos++;            
        }
        // if eof, wait stay there and keep checking
        else
        {
            usleep(1000000); // period = 1s
        }                     
    }

    if (file.is_open())
        file.close();    
}

bool TestComy::safeRead(std::fstream& file, int readPos)
{
    LOG4CXX_INFO(logger, "safeRead: check " << readPos);                                
    file.seekg(readPos, std::fstream::beg);        
    if (file.fail())
    {
        LOG4CXX_WARN(logger, "safeRead: seek failed");                                
        LOG4CXX_WARN(logger, "safeRead: new pos " << file.tellg());                                
        return false;
    }
    else
    {
        char c = file.peek();
        if (c == EOF)
        {
            LOG4CXX_WARN(logger, "safeRead: peek EOF");                                
            LOG4CXX_WARN(logger, "safeRead: new pos " << file.tellg());   
            file.clear();
            return false;
        }
        else
        {
            LOG4CXX_INFO(logger, "safeRead: peeked " << c);                                
            return true;
        }
    }
}

void TestComy::testFileReading2()
{
    LOG4CXX_INFO(logger, modName + ": testFileReading ...");
    
    std::string filename = "/home/albarral/coms/testfile.txt";
    std::ifstream infile;     

    infile.open(filename);           
    if (!infile.is_open())
    {
        LOG4CXX_ERROR(logger, modName + "file not opened");                        
        return;
    }
    
    int maxSeconcds = 15;
    std::string line;
    for (int i = 0; i < maxSeconcds; i++)
    {
        LOG4CXX_INFO(logger, "i = " << i);    
        // check safe reading
        
        while (std::getline(infile, line))
        {
            LOG4CXX_INFO(logger, "read: " << line);   
        }

        refreshWhenEOF(infile);
        usleep(1000000); // period = 1s
    }

    if (infile.is_open())
        infile.close();    
}

void TestComy::refreshWhenEOF(std::ifstream& file)
{
    if (file.eof())
    {
        LOG4CXX_WARN(logger, "EOF -> file refreshed");                                
        file.clear();    
    }
}

void TestComy::testComsPublishSubscribe()
{
    LOG4CXX_INFO(logger, modName + ": testComsPublishSubscribe ...");
       
    comy::ComyFilePublisher oComyPublisher;
    comy::ComyFileSubscriber oComySubscriber;
    
    // connection
    // multichannel communication
    std::string topic = "topic";
    std::string category = "cat";
    oComyPublisher.connect(topic, category);
    oComySubscriber.connect(topic, category);
    
    if (!oComyPublisher.isConnected() || !oComySubscriber.isConnected())
    {
        LOG4CXX_ERROR(logger, modName + ": client or server not connected. Exit test!");                        
        return;
    }
    
    // send message 1
    std::string msg = "hola, hay alguien?";            
    oComyPublisher.publishMessage(msg);
    LOG4CXX_INFO(logger, modName + ": message sent ... " + msg);                

    // receive message
    bool bmsgReceived = false;
    while (!bmsgReceived)
    {
        if (oComySubscriber.readMessage())
        {
            bmsgReceived = true;
            LOG4CXX_INFO(logger, modName + ": message received ... " + oComySubscriber.getRawMessage());                
        }            
        usleep(100000); // period = 100ms
    }    

    
}

void TestComy::readByServer(comy::ComyFileServer& oComyServer)
{
    oComyServer.readMessages();
    LOG4CXX_INFO(logger, "server has messages " + std::to_string(oComyServer.getQueueSize()));                
    while (oComyServer.hasMessages())
    {
        std::string message = oComyServer.getMessage();
        if (!message.empty())
        {
            LOG4CXX_INFO(logger, modName + ": message received ... " + message);                
        }            
    }
}