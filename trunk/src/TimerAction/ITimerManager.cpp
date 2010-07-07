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

bool utime::operator==(utime& comp) {
    return ((sec == comp.sec) && (usec == comp.usec));
}

bool utime::operator!=(utime& comp) {
    return !operator==(comp);
}

utime& utime::operator+(utime& comp) {
    usec += comp.usec;
    sec += comp.sec + usec / 1000000;
    usec = usec % 1000000;
    return *this;
}

utime& utime::operator-(utime& comp) {
    usec -= comp.usec;
    sec -= comp.sec;
    if (usec < 0)
    {
        sec -= 1;
        usec = 1000000 + usec;
    }
    return *this;
}