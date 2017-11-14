/***************************************************************************
 *   Copyright (C) 2017 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/


#include "talky/Talk2Target.h"
#include "talky/coms/Message.h"


namespace talky
{
log4cxx::LoggerPtr Talk2Target::logger(log4cxx::Logger::getLogger("talky"));

Talk2Target::Talk2Target()
{    
    benabled = false;
}
    
Talk2Target::~Talk2Target()
{
    listCommands.clear();
}

void Talk2Target::init(int topic, int category)
{    
    // if reinitialization, reset interpreter
    if (benabled)
    {
        oInterpreter.reset();
        benabled = false;
    }
    
    // prepare interpreter for the topic
    oInterpreter.addLanguage(topic);

    // if category is known, initialization is good
    if (oInterpreter.knowsTopicCategory(topic, category))
    {        
        this->topic = topic;
        this->category = category;
        benabled = true;
    }
}
    
void Talk2Target::addCommand(int concept, float quantity)
{  
    std::lock_guard<std::mutex> locker(mutex);
    
    Command oCommand;
    oCommand.setTopic(topic);
    oCommand.setCategory(category);
    oCommand.setConcept(concept);
    oCommand.setQuantity(quantity);
    
    listCommands.push_back(oCommand);
}

void Talk2Target::addCommand(int concept)
{  
    std::lock_guard<std::mutex> locker(mutex);
    
    Command oCommand;
    oCommand.setTopic(topic);
    oCommand.setCategory(category);
    oCommand.setConcept(concept);
    
    listCommands.push_back(oCommand);
}

bool Talk2Target::isArmed()
{
    std::lock_guard<std::mutex> locker(mutex);
    
    return (!listCommands.empty());    
}

bool Talk2Target::processCommand()
{
    std::lock_guard<std::mutex> locker(mutex);

    // skip if no pending commands
    if (listCommands.empty())
       return false;
    
    bool bok = false;
    // get oldest command in list
    Command& oCommand = listCommands.front();    
    // create simple message
    Message oMessage;
    
    // build message from command
    if (oInterpreter.buildSimpleMessage(oCommand, oMessage))
    {
        // if well built get raw text
        message = oMessage.getRawText();
        bok = true;
    }
    else
    {
        message = "";
        bok = false;
        LOG4CXX_WARN(logger, "Talk2Target: command not processed! " + oCommand.toString());    
    }
    
    // remove processed command from list
    listCommands.pop_front();
    
    return bok;    
}

}