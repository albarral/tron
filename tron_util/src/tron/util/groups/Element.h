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
    int id;            // element id 
    int group;      // group to which element belongs
    std::string name;   // element name
    int type;         // element tyoe (one of eTypes)

public:
    Element();
    Element(int id, std::string name);
    //~Element();
    
    void setID(int value) {id = value;};
    void setName(std::string value) {name = value;};
    void setGroup(int value) {group = value;};
    
    int getID() {return id;}; 
    int getGroup() {return group;}; 
    std::string getName() {return name;}; 

    bool isElement() {return (type == eTYPE_ELEMENT);};
    bool isGroup() {return (type == eTYPE_GROUP);};
    bool isSuperGroup() {return (type == eTYPE_SUPERGROUP);};
    
    virtual std::string toString();
    
    // gets name of type
    static std::string getTypeName(int type);
};

}  

#endif
