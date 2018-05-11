#ifndef __TRON_UTIL_ELEMENT_H
#define __TRON_UTIL_ELEMENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron
{
// Base class definition of a group's element.
class Element
{
public:
    enum eTypes
    {
        eTYPE_ELEMENT,
        eTYPE_GROUP,
        eTYPE_SUPERGROUP
    };
    
protected:
    int id; 
    std::string name;
    int type;         // one of eTypes
    int group;      // group to which element belongs

public:
    Element();
    Element(int id, std::string name);
    //~Element();
    
    void setID(int value) {id = value;};
    void setName(std::string value) {name = value;};
    void setGroup(int value) {group = value;};
    
    int getID() {return id;}; 
    std::string getName() {return name;}; 
    int getGroup() {return group;}; 

    bool isElement() {return (type == eTYPE_ELEMENT);};
    bool isGroup() {return (type == eTYPE_GROUP);};
    bool isSuperGroup() {return (type == eTYPE_SUPERGROUP);};
    
    virtual std::string toString();
    
    // gets name of type
    static std::string getTypeName(int type);
};

}  

#endif
