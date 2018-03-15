#ifndef __TRON_ROBOT_ANYCLIENT_H
#define __TRON_ROBOT_ANYCLIENT_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

namespace tron
{
// Interface class for any robot client
class TronAnyClient
{        
 public:     
    // full stop of control actions 
    virtual bool fullStop() = 0;
    // end control process
    virtual bool endNode() = 0;        

};
}
#endif
