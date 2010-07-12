/* 
 * File:   MovementPolicy.hpp
 * Author: Errata
 *
 * Created on July 12, 2010, 3:15 PM
 */

#ifndef _MOVEMENTPOLICY_HPP
#define	_MOVEMENTPOLICY_HPP

#include "MovementType.h"
#include "TimerManager/ITimerManager.hpp"

struct Position {
    unsigned int _posX;
    unsigned int _posY;
    Position(unsigned int posX, unsigned int posY);
};

class MovementPolicy {
public:
    MovementPolicy(Position& init);
    MovementPolicy(const MovementPolicy& orig);
    virtual ~MovementPolicy();
    virtual Position GetPositionAt(mtime& time) = 0;
    virtual Position GetPosition(void) = 0;
    virtual MovementType GetMovementType(void) = 0;

protected:
    Position _pos;

private:
    ITimerManager::timeHdl _timeHandler;
    ITimerManager* _timerMan;
};

#endif	/* _MOVEMENTPOLICY_HPP */

