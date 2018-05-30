/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ZeroClientChannel.cpp
 * Author: oorra
 * 
 * Created on May 30, 2018, 6:15 PM
 */

#include "ZeroClientChannel.h"

namespace tron
{
    ZeroClientChannel::ZeroClientChannel()
    {    
    }

    ZeroClientChannel::ZeroClientChannel(int node, int channel) : ClientChannel(node, channel)
    {
    }

    ZeroClientChannel::~ZeroClientChannel()
    {
    }

    bool ZeroClientChannel::open()
    {
    }

    bool ZeroClientChannel::close()
    {        
    }

    bool ZeroClientChannel::sendMsg(std::string message)
    {
    }

    bool ZeroClientChannel::sendMessages(std::vector<std::string>& listMessages)
    {
    }

}

