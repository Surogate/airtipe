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

const Position VectorialMovement::GetPositionAt(mtime& time) const {
    mtime timeFrom = _timerMan->GetTimeFrom(_timeHandler);
    timeFrom = timeFrom + time;
    float fTime = timeFrom.toFloat();
    return Position((fTime * incX) + _posInit._posX, (fTime * incY) + _posInit._posY);
}

const Position VectorialMovement::GetPosition() const {
    mtime time;
    return GetPositionAt(time);
}
