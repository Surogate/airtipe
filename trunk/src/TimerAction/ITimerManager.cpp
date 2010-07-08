/*!
 * \file    ITimeManager.cpp
 * \brief   Implementation of ITimeManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 7:06 PM
 */

#include "ITimerManager.hpp"

ITimerManager::~ITimerManager() {
}

bool mtime::operator==(mtime& comp) {
    return ((sec == comp.sec) && (msec == comp.msec));
}

bool mtime::operator!=(mtime& comp) {
    return !operator==(comp);
}

mtime& mtime::operator+(mtime& comp) {
    msec += comp.msec;
    sec += comp.sec + msec / 1000;
    msec = msec % 1000;
    return *this;
}

mtime& mtime::operator-(mtime& comp) {
    msec -= comp.msec;
    sec -= comp.sec;
    if (msec < 0)
    {
        sec -= 1;
        msec = 1000 + msec;
    }
    return *this;
}
