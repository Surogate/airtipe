/* 
 * File:   VectorialMovement.h
 * Author: Errata
 *
 * Created on July 19, 2010, 4:23 PM
 */

#ifndef VECTORIALMOVEMENT_H
#define	VECTORIALMOVEMENT_H

#include "MovementPolicy.h"


class VectorialMovement : MovementPolicy {
public:
    VectorialMovement(const Position& init, const Position&, const int);
    const Position GetPositionAt(mtime& time);
    const Position GetPosition() const;
    const MovementType GetMovementType(void) const;
private:
    float incX;
    float incY;
};

#endif	/* VECTORIALMOVEMENT_H */

