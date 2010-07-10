/*!
 * \file    ITimeManager.cpp
 * \brief   Implementation of ITimeManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 7:06 PM
 */

#include <iostream>
#include "ITimerManager.hpp"

ITimerManager::~ITimerManager() {
}

mtime::mtime(long int sec_, long int msec_) {
    sec = sec_;
    msec = msec_;
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
    long int _msec;
    long int _sec;

    _msec = msec - comp.msec;
    _sec = sec - comp.sec;
    if (_msec < 0)
    {
        _sec -= 1;
        _msec = 1000 + _msec;
    }
    sec = _sec;
    msec = _msec;
    return *this;
}
