/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/topics/ExtraSection.h"

namespace tron
{
const std::string ExtraSection::EXTRA_SECTION = "extra";    

ExtraSection::ExtraSection() : NodeSection(ExtraSection::eEXTRA_SECTION)
{
    oChannelsMap.addCode(eEXTRA_STOP, EXTRA_STOP);
    oChannelsMap.addCode(eEXTRA_END, EXTRA_END);     
}
}