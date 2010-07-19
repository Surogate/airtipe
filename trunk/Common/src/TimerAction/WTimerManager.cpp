/*!
 * \file    WTimerManager.cpp
 * \brief   Implementation of WTimerManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 5:52 PM
 */

#ifdef WIN32

# include <time.h>
# include <iostream>
# include <cmath>
# include <winsock2.h>
# include "TimerManager/WTimerManager.hpp"

WTimerManager::WTimerManager() {
    getTime(actionTime_);
    getTime(actionval_);
    listTime_.clear();
}

WTimerManager::WTimerManager(const WTimerManager& orig)
: ITimerManager(), actionTime_(orig.actionTime_), actionval_(orig.actionval_), listTime_(orig.listTime_) {
}

WTimerManager::~WTimerManager() {
}

void WTimerManager::SetActualTime(const mtime timestamps) {
    actionTime_ = timestamps;
    getTime(actionval_);
}

mtime WTimerManager::GetActualTime() {
    mtime actual;
    getTime(actual);
    mtime ret = actionTime_ + (actual - actionTime_);
    return ret;
}

const ITimerManager::timeHdl WTimerManager::setTimer() {
    mtime time;
    getTime(time);
    listTime_.push_back(time);
    return listTime_.size() -1;
}

mtime WTimerManager::GetTimeFrom(const timeHdl& hdler) const {
    mtime ret;
    
    if (isValid(hdler)){
        mtime actual;
        mtime two = listTime_[hdler];
        getTime(actual);
        ret.valid = true;
        ret = actual - two;
        return ret;
    }
    ret.valid = false;
    return ret;
}

inline bool WTimerManager::isValid(const ITimerManager::timeHdl& hdler) const {
    if (hdler >= 0)
        return (static_cast<unsigned int>(hdler) < listTime_.size());
    return false;
}

mtime WTimerManager::GetTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const {
    mtime ret;

    if (isValid(hdl1) && isValid(hdl2))
    {
        mtime one = listTime_[hdl1];
        mtime two = listTime_[hdl2];
        ret = one - two;
        ret.valid = true;
        return ret;
    }
    ret.valid = false;
    return ret;
}

mtime WTimerManager::GetUnTimeBetween(const ITimerManager::timeHdl& hdl1, const ITimerManager::timeHdl& hdl2) const {
    mtime ret;

    if (hdl1 < hdl2)
        ret = GetTimeBetween(hdl2, hdl1);
    else
        ret = GetTimeBetween(hdl1, hdl2);
    return ret;
}

mtime WTimerManager::GetTimeFromLast() const {
    mtime ret;
    if (listTime_.empty())
    {
        ret.valid = false;
        return ret;
    }
    return GetTimeFrom(listTime_.size() - 1);
}

const bool WTimerManager::good() const {
    return !error;
}

void WTimerManager::wait(const mtime& time) const {
    clock_t goal = (time.sec * CLOCKS_PER_SEC) + (time.msec * CLOCKS_PER_SEC / 1000) + clock();
    while(goal > clock()){
        Sleep(1);
    }
}

void WTimerManager::getTime(mtime& ret) {
    _SYSTEMTIME time;
    GetSystemTime(&time);
    setTime(ret, time);
}

void WTimerManager::getTime(mtime& ret) const {
    _SYSTEMTIME time;
    GetSystemTime(&time);
    setTime(ret, time);
}

void WTimerManager::setTime(mtime& ret, const _SYSTEMTIME& val) {
    ret.sec = time(NULL);
    ret.msec = val.wMilliseconds;
    ret.valid = true;
}

void WTimerManager::setTime(mtime& ret, const _SYSTEMTIME& val) const {
    ret.sec = time(NULL);
    ret.msec = val.wMilliseconds;
    ret.valid = true;
}

#endif // WIN32
