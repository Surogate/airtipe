/*!
 * \file    NoMovement.h
 * \brief   Implementation of NoMovement class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 16, 2010 1:41 PM
 */

#ifndef _NOMOVEMENT_H
#define	_NOMOVEMENT_H

#include "MovementPolicy.h"


class NoMovement : MovementPolicy {
public:
    NoMovement(const Position& init, const Position&, const int);
    const Position GetPositionAt(mtime& time);
    MovementType GetMovementType(void);
};

#endif	/* _NOMOVEMENT_H */

