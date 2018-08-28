/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/channels/ExtraSection.h"

namespace tron
{
const std::string ExtraSection::EXTRA_SECTION = "extra";    

ExtraSection::ExtraSection(int sectionCode) : NodeSection(sectionCode)
{
    oChannelsMap.addCode(eEXTRA_STOP, EXTRA_STOP);
    oChannelsMap.addCode(eEXTRA_END, EXTRA_END);     
}
}