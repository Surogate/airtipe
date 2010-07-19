
/*!
 * \file    NoMovement.cpp
 * \brief   Implementation of NoMovement class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 16, 2010 1:41 PM
 */

#include "CircularMovementRight.h"

CircularMovementRight::CircularMovementRight(const Position& init, const Position& circleCenter, const int radPerSec, bool sens)
: MovementPolicy(init, circleCenter, radPerSec)
{}

MovementType CircularMovementRight::GetMovementType() {
    return Circular;
}

const Position CircularMovementRight::GetPositionAt(mtime& time) {
    Position actual;
    mtime timeFrom = _timerMan->GetTimeFrom(_timeHandler);
    timeFrom = timeFrom + time;
    
    return actual;
}

