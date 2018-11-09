/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <vector>

#include "TestSpace.h"
#include "tron/space/Space.h"

using namespace log4cxx;

LoggerPtr TestSpace::logger(Logger::getLogger("tron"));

// Constructor 
TestSpace::TestSpace()
{    
    modName = "TestSpace";
 }

void TestSpace::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    //testBoard();
    testBoards();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestSpace::createBoard()
{
    LOG4CXX_INFO(logger, modName + ": createBoard ...");
    
    tron::Space oSpace(1);    
    oBoard.addSpace(oSpace);
    oBoard.addSpace(oSpace);
    oBoard.checkState();
}

void TestSpace::createElements()
{
    LOG4CXX_INFO(logger, modName + ": createElements ...");
    
    listElements1 = {10, 20, 30};
    listElements2 = {20, 30, 40};    
}

void TestSpace::fillSpace(tron::Board& oBoard, int spaceID, std::vector<int>& listElements)
{
    // access space
    tron::Space* pSpace = oBoard.getSpace(spaceID);
    if (pSpace != nullptr)
    {
        for (int element : listElements)
            pSpace->addElement(element);
    }            
}

void TestSpace::testBoard()
{
    LOG4CXX_INFO(logger, modName + ": testBoard ...");

    createBoard();
    createElements();

    // put elements in space 0
    fillSpace(oBoard, 0, listElements1);     
    // put elements in space 1
    fillSpace(oBoard, 1, listElements2); 

    oBoard.checkState();
    LOG4CXX_INFO(logger, oBoard.toString());
    
    // compare spaces
    tron::Space* pSpace1 = oBoard.getSpace(0);
    tron::Space* pSpace2 = oBoard.getSpace(1);
    if (*pSpace1 == *pSpace2)
    {
        LOG4CXX_INFO(logger, "spaces are equal");        
    }
    else
    {
        LOG4CXX_INFO(logger, "spaces are different");        
    }
}

void TestSpace::testBoards()
{
    LOG4CXX_INFO(logger, modName + ": testBoards ...");

    createBoard();
    createElements();

    // put elements in space 0
    fillSpace(oBoard, 0, listElements1);     
    // put elements in space 1
    fillSpace(oBoard, 1, listElements2); 

    oBoard.checkState();
    LOG4CXX_INFO(logger, oBoard.toString());

    // create second board equal to first
    tron::Board oBoard2;
    oBoard2 = oBoard;
    // remove one element
    oBoard2.getSpace(0)->clearElement(30);

    LOG4CXX_INFO(logger, oBoard2.toString());
    
    // compare boards
    if (oBoard == oBoard2)
    {
        LOG4CXX_INFO(logger, "boards are equal");        
    }
    else
    {
        LOG4CXX_INFO(logger, "boards are different");        
    }
}

