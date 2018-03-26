/***************************************************************************
 *   Copyright (C) 2018 by Migtron Robotics   *
 *   albarral@migtron.com   *
 ***************************************************************************/

#include "tron/moves/MoveFactory.h"
#include "tron/moves/CircularMovement.h"
#include "tron/moves/WaveMovement.h"
#include "tron/language/objects/FiguresTheme.h"

namespace tron
{
MoveFactory::MoveFactory()
{
    pCyclicMovement = 0;
}

MoveFactory::~MoveFactory()
{
    if (pCyclicMovement != 0)
        delete(pCyclicMovement);
}

bool MoveFactory::generateMovement(int figure)
{
    if (pCyclicMovement != 0)
        delete(pCyclicMovement);
    
    bool bok = true;
    switch (figure)
    {
        case tron::FiguresTheme::eFIGURE_LINE:
        {
            WaveMovement* pWaveMovement = new WaveMovement();
            pWaveMovement->createLine(freq, size, angle);
            pCyclicMovement = pWaveMovement;
        }
            break;            
        case tron::FiguresTheme::eFIGURE_WAVE:
        {
            WaveMovement* pWaveMovement = new WaveMovement();
            pWaveMovement->createWave(freq, size, relFactor, relFreq, angle);
            pCyclicMovement = pWaveMovement;
        }
            break;            
        case tron::FiguresTheme::eFIGURE_CIRCLE:
        {
            CircularMovement* pCircularMovement = new CircularMovement();
            pCircularMovement->createCircle(freq, size, angle, brotation);
            pCyclicMovement = pCircularMovement;
        }
            break;
        case tron::FiguresTheme::eFIGURE_ELLIPSE:
        {
            CircularMovement* pCircularMovement = new CircularMovement();
            pCircularMovement->createEllipse(freq, size, relFactor, angle, brotation);
            pCyclicMovement = pCircularMovement;
        }
            break;            
        default: 
            pCyclicMovement = 0;
            bok = false;
            break;
    }
    return bok;
}

}