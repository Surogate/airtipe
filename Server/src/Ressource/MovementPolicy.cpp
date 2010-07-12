/* 
 * File:   MovementPolicy.cpp
 * Author: Errata
 * 
 * Created on July 12, 2010, 3:15 PM
 */

#include "../../inc/MovementPolicy.h"

Position::Position(unsigned int posX, unsigned int posY)
: _posX(posX), _posY(posY) {}

MovementPolicy::MovementPolicy(Position& Init)
: _pos(Init) {
}

MovementPolicy::MovementPolicy(const MovementPolicy& orig)
: _pos(orig._pos), _timeHandler(orig._timeHandler), _timerMan(orig._timerMan) {
}

MovementPolicy::~MovementPolicy() {
}

