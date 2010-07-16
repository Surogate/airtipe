/*!
 * \file    NoMovement.cpp
 * \brief   Implementation of NoMovement class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 16, 2010 1:41 PM
 */

#include "NoMovement.h"

NoMovement::NoMovement(const Position& init, const Position&, const int)
: MovementPolicy(init) {
}

MovementType NoMovement::GetMovementType() {
    return ::NoMovement;
}

const Position NoMovement::GetPositionAt(mtime& time) {
    return _posInit;
}

const Position NoMovement::GetPosition() const {
    return _posInit;
}