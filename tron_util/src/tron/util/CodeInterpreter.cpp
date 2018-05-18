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
    clearKnowledge();
}

void CodeInterpreter::clearKnowledge()
{
    oCodeMap.reset();    
    benabled = false;
}

void CodeInterpreter::addKnowledge(std::vector<Code> listCodes)
{
    // add given codes to the knowledge map
    for (tron::Code& oCode : listCodes)
    {
        oCodeMap.addCode(oCode.getID(), oCode.getName());
    }
    // set enabled when there's some knowledge
    benabled = oCodeMap.getSize() > 0;
}

void CodeInterpreter::addKnowledge(int codeId, std::string codeName)
{
    // add given code to the knowledge map
    oCodeMap.addCode(codeId, codeName);
    // set enabled as there's some knowledge
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