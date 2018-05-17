#ifndef __TRON_UTIL_CODE_H
#define __TRON_UTIL_CODE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron
{
// Definition of a generic code: an entity with a name and numeric ID.
class Code
{
private:
    int id; 
    std::string name;

public:
    Code();
    Code(int id, std::string name);
    //~Code();
    
    void setID(int value) {id = value;};
    void setName(std::string value) {name = value;};
    
    int getID() {return id;}; 
    std::string getName() {return name;}; 
    
    std::string toString();
};

}  

#endif
