/* 
 * File:   MovementPolicy.cpp
 * Author: Errata
 * 
 * Created on July 12, 2010, 3:15 PM
 */

#include "MovementPolicy.h"
#include "singleton/SingletonHolder.h"

Position::Position(float posX, float posY)
: _posX(posX), _posY(posY) {
}

MovementPolicy::MovementPolicy(const Position& Init, const Position& direction, const int velocity)
: _posInit(Init), _direct(direction), _vel(velocity) {
    _timerMan = SingletonHolder< ITimerManager, AbsPolicyCreatorNew >::getInstance();
    _timeHandler = _timerMan->setTimer();
}

MovementPolicy::MovementPolicy(const MovementPolicy& orig)
: _posInit(orig._posInit), _direct(orig._direct), _vel(orig._vel) {
   _timerMan = SingletonHolder< ITimerManager, AbsPolicyCreatorNew >::getInstance();
   _timeHandler = _timerMan->setTimer();
}

MovementPolicy::~MovementPolicy() {
}
