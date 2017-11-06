#ifndef __TALKY_DATABLOCK_H
#define __TALKY_DATABLOCK_H

/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include <string>
#include <vector>

#include "talky/coms/CommandBlock.h"

namespace talky
{
// Base class used to encapsulate talky data in blocks. 
class DataBlock
{    
   protected:
        int topic;    
        int category;    
        std::string blockName;    
        std::vector<int> listElements;    

    public:
        // reset all values
        void reset();        

        void setTopic(int value) {topic = value;}
        void setCategory(int value) {category = value;}
        void setBlockName(std::string value) {blockName = value;}
        void addElement(int value);

        float getTopic() {return topic;};        
        float getCategory() {return category;};        
        std::string getBlockName() {return blockName;};        
        std::vector<int>& getListElements() {return listElements;};        

        // checks if given command block holds the elements of this data block
        bool checkCompatibleBlock(CommandBlock& oCommandBlock);
        
        // returns a description of the object
        virtual std::string toString();        
};

}    
#endif
