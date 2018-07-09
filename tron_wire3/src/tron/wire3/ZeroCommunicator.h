#ifndef ZEROCOMMUNICATOR_H
#define ZEROCOMMUNICATOR_H

/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   oriolorra@migtron.com   *
 ***************************************************************************/

#include <string>

namespace tron
{
    class ZeroCommunicator {

        protected:

            int port_;

        public:
            ZeroCommunicator();

            int getPort() {return port_;};

        protected:    
            void setPort(int node, int channel);
    };
}

#endif /* ZEROCOMMUNICATOR_H */

