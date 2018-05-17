/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/util/CodeInterpreter.h"

namespace tron
{
CodeInterpreter::CodeInterpreter()
{
    benabled = false;
}

CodeInterpreter::~CodeInterpreter()
{
    reset();
}

void CodeInterpreter::reset()
{
    oCodeMap.reset();    
    benabled = false;
}

void CodeInterpreter::setKnowledge(std::vector<Code> listCodes)
{
    // fills code map with the topic's code map elements
    for (tron::Code& oCode : listCodes)
    {
        oCodeMap.addCode(oCode.getID(), oCode.getName());
    }

    if (listCodes.size() > 0)
        benabled = true;
}

int CodeInterpreter::interpretCode(std::string& word)
{
    int codeId;
    // search code by name, if known return its id 
    if (oCodeMap.getCode4Name(word, codeId))
        return codeId;
    // otherwise return unknown
    else
        return -1;
}

std::string CodeInterpreter::writeCode(int number)
{
    std::string codeName;

    // search code by id, if known return its name 
    if (oCodeMap.getName4Code(number, codeName))
        return codeName;
    // otherwise return unknown
    else
        return "";
}

std::string CodeInterpreter::describeKnowledge()
{
    return oCodeMap.toString();
}

}