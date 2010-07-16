/*!
 * \file    NoMovement.cpp
 * \brief   Implementation of NoMovement class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 16, 2010 1:41 PM
 */

#include "NoMovement.h"

NoMovement::NoMovement() {
}

NoMovement::NoMovement(const NoMovement&) {
}

NoMovement::~NoMovement() {
}

NoMovement& NoMovement::operator=(const NoMovement& cpy) {
    if (this != &cpy) {
    }
    return *this;
}
