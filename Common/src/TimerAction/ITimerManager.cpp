/*!
 * \file    ITimeManager.cpp
 * \brief   Implementation of ITimeManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 7:06 PM
 */

#include <iostream>
#include "TimerManager/ITimerManager.hpp"
#ifdef WIN32
# include "TimerManager/WTimerManager.hpp"
#else
# include "TimerManager/LTimerManager.hpp"
#endif

ITimerManager::~ITimerManager() {
}

mtime::mtime(long int sec_, long int msec_) {
    sec = sec_;
    msec = msec_;
}

mtime::mtime(float time) {
    sec = time;
    msec = (time * 1000) % 1000;
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

float mtime::toFloat() const {
    float time = sec;
    time += msec / 1000;
    return time;
}

template<typename Class, typename RetType, typename Param1, typename Param2>
void ITimerManager::waitTo(const mtime& time, Functor<Class,RetType,Param1,Param2>& func, Param1& arg1, Param2& arg2) const {
    wait(time);
    func.call(arg1, arg2);
}

template<typename Class, typename RetType, typename Param1>
void ITimerManager::waitTo(const mtime& time, Functor<Class,RetType,Param1>& func, Param1& arg1) const {
    wait(time);
    func.call(arg1);
}

template<typename Class, typename RetType>
void ITimerManager::waitTo(const mtime& time, Functor<Class,RetType>& func) const {
    wait(time);
    func.call();
}

ITimerManager* ITimerManager::AbsNew() {
	#ifdef WIN32
		return new WTimerManager;
	#else
		return new LTimerManager;
	#endif
}
