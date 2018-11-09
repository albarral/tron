#ifndef __TRON_TEST_SPACE_H
#define __TRON_TEST_SPACE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>
#include <log4cxx/logger.h>

#include "tron/space/Board.h"

// Class used to test tron_space lib.
class TestSpace
{
private:
    static log4cxx::LoggerPtr logger;
    std::string modName;          // module name
    tron::Board oBoard; 
    std::vector<int> listElements1;
    std::vector<int> listElements2;

public:
    TestSpace();
    //~TestSpace();

    void makeTest();      
    
private:
    void createBoard();
    void createElements();
    // put given elements in specified space of given board
    void fillSpace(tron::Board& oBoard, int spaceID, std::vector<int>& listElements);
    void testBoard();
    void testBoards();
};
#endif
