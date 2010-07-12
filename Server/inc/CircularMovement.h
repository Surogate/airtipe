/* 
 * File:   CircularMovement.h
 * Author: Errata
 *
 * Created on July 12, 2010, 5:52 PM
 */

#ifndef _CIRCULARMOVEMENT_H
#define	_CIRCULARMOVEMENT_H

#include "MovementPolicy.h"

class CircularMovement : public MovementPolicy {
public:
    CircularMovement(const Position& init, const Position& circleCenter, const int radPerSec = 1, bool sens = true);
    const Position GetPositionAt(mtime& time);
    MovementType GetMovementType(void);

private:
    bool _sens;
};

#endif	/* _CIRCULARMOVEMENT_H */

