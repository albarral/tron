#ifndef __TRON_MATH_COORDINATES_H
#define __TRON_MATH_COORDINATES_H

/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/
	
namespace tron 
{
 class Coordinates
{
 private:
    static const float K180_DIV_PI;  // constant 180/PI

 public:
     //Coordinates ();
     //~Coordinates();
     
     // converts cartesian coordinates to polar coordinates
    static void cartesian2polar (float x, float y, float& magnitude, float& angle);

     //static void polar2cartesian (float magnitude, float angle, float& x, float& y);
};  
}  
#endif
