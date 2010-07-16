
#include "CircularMovement.h"

CircularMovement::CircularMovement(const Position& init, const Position& circleCenter, const int radPerSec, bool sens)
: MovementPolicy(init, circleCenter, radPerSec), _sens(sens) {
}

MovementType CircularMovement::GetMovementType() {
    return Circular;
}

const Position CircularMovement::GetPositionAt(mtime& time) {
    mtime timeFrom = _timerMan->GetTimeFrom(_timeHandler);
    timeFrom = timeFrom + time;
}

