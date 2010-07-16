/* 
 * File:   MovementPolicy.hpp
 * Author: Errata
 *
 * Created on July 12, 2010, 3:15 PM
 */

#ifndef _MOVEMENTPOLICY_HPP
#define	_MOVEMENTPOLICY_HPP

#include "MovementType.h"
#include "singleton/SingletonHolder.h"
#include "TimerManager/ITimerManager.hpp"

struct Position {
    unsigned int _posX;
    unsigned int _posY;
    Position(unsigned int posX = 0, unsigned int posY = 0);
};

class MovementPolicy {
public:
    MovementPolicy(const Position& init, const Position& direction = Position(), const int velocity = 0);
    MovementPolicy(const MovementPolicy& orig);
    virtual ~MovementPolicy();
    virtual const Position GetPosition(void) const = 0;
    virtual const Position GetPositionAt(mtime& time) = 0;
    virtual const MovementType GetMovementType(void) const = 0;

protected:
    const Position _posInit;
    const Position _direct;
    const int _vel;
    ITimerManager::timeHdl _timeHandler;
    ITimerManager* _timerMan;
};

#endif	/* _MOVEMENTPOLICY_HPP */
