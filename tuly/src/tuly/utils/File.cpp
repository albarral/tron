/***************************************************************************
 *   Copyright (C) 2016 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tuly/utils/File.h"

namespace tuly 
{
File::File()
{
    filename = "";    
}

bool File::isOpen()
{
    return (file.is_open());
}

bool File::close()
{
    bool bok = false;
    // proceed if open 
    if (file.is_open())
    {        
        file.close();
        filename = "";
        bok = true;
    }

    return bok;
}
}