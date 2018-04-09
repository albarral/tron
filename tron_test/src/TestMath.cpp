/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <unistd.h>

#include "TestMath.h"
#include "tron/math/ArmMath.h"


using namespace log4cxx;

LoggerPtr TestMath::logger(Logger::getLogger("tron"));

// Constructor 
TestMath::TestMath()
{    
    modName = "TestMath";
 }

void TestMath::makeTest()
{
    LOG4CXX_INFO(logger, modName + ": test start \n");

    LOG4CXX_INFO(logger, "\n");
    testArmMath();
        
    LOG4CXX_INFO(logger, modName + ": test end \n");
};

void TestMath::testArmMath()
{
    tron::ArmMath oArmMath;
    oArmMath.setLengths(20,80);
    
    float tilt, radius;
    float angleVS, angleEL;

    angleVS = 90; 
    angleEL = -160;
    
    for (int i=0; i<4; i++)
    {
        tilt = oArmMath.computeTilt4JointAngles(angleVS, angleEL);
        radius = oArmMath.computeRadius4ElbowAngle(angleEL);
        LOG4CXX_INFO(logger, "angleVS: " << angleVS << ", angleEL: " << angleEL << ", radius= " << radius << ", tilt= " << tilt << "\n");
        angleVS -= 30;
    }

//    radius = 40;
//    float angle = oArmMath.calcElbowAngle(radius);
//    LOG4CXX_INFO(logger, "radius: " << radius << ", angle = " << angle << "\n");
}


