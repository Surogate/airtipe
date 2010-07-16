
#include "CircularMovementRight.h"

CircularMovementRight::CircularMovementRight(const Position& init, const Position& circleCenter, const int radPerSec, bool sens)
: MovementPolicy(init, circleCenter, radPerSec) {
}

MovementType CircularMovementRight::GetMovementType() {
    return Circular;
}

const Position CircularMovementRight::GetPositionAt(mtime& time) {
    mtime timeFrom = _timerMan->GetTimeFrom(_timeHandler);
    timeFrom = timeFrom + time;
    
}

