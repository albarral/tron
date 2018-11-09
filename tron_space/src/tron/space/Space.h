#ifndef __TRON_SPACE_SPACE_H
#define __TRON_SPACE_SPACE_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <list>
#include <string>

namespace tron
{
// Class representing a board space, which can be filled with elements.    
// It's state is automatically updated (empty, filled or multi-filled).
class Space
{
public:   
 enum eState
{
    eSPACE_EMPTY,               // no elements present
    eSPACE_FILLED,              // one element present
    eSPACE_MULTI_FILLED     // various elements present
};

protected:
    int ID; 
    int state;
    std::list<int> listElements;    // elements present in the board space

public:
    Space(int id);
    ~Space();

    int getID() {return ID;};
    int getState() {return state;};
    std::list<int>& getElements() {return listElements;};
    int getNumElements() {return listElements.size();};    
    
    void setID(int id) {ID = id;};
    // add given element to space
    void addElement(int element);
    // remove given element from space
    bool clearElement(int element);
    // check if given element exists in this space
    bool findElement(int element);
    
    // clear space (all elements)
    void clear();

    // compare operator (return true if spaces equal)
    friend bool operator== (Space& s1, Space& s2);
    
    // get name of given state
    static std::string getStateName(int state);    
    std::string toString();
    
private:
    // updates space state (depending on elements count)
    void updateState();
};

}  

#endif
