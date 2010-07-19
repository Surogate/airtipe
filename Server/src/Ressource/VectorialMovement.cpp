/* 
 * File:   VectorialMovement.cpp
 * Author: Errata
 * 
 * Created on July 19, 2010, 4:23 PM
 */

#include "VectorialMovement.h"

VectorialMovement::VectorialMovement(const Position& init, const Position& to, const int vel)
: MovementPolicy(init, to, vel) {
    incX = init._posX - to._posX;
    incY = init._posY - to._posY;
}

const MovementType VectorialMovement::GetMovementType() const {
    return Vectorial;
}

const Position VectorialMovement::GetPositionAt(mtime& time) {
    mtime timeFrom = _timerMan->GetTimeFrom(_timeHandler);
    timeFrom = timeFrom + time;
    float Ftime = timeFrom.toFloat();
    return Position((Ftime * incX) + _posInit._posX, (Ftime * incY) + _posInit._posY);
}
