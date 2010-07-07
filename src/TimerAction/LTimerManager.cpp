/*!
 * \file    LTimerManager.cpp
 * \brief   Implementation of LTimerManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 5:52 PM
 */

#include "LTimerManager.hpp"

LTimerManager::LTimerManager()
{
    listTime_.clear();
    gettimeofday(&actionval_, 0);
    actionTime_.sec = actionval_.tv_sec;
    actionTime_.usec = actionval_.tv_usec;
}

LTimerManager::LTimerManager(const LTimerManager& cpy)
: actionval_(cpy.actionval_), actionTime_(cpy.actionTime_), listTime_(cpy.listTime_) {
}

LTimerManager::~LTimerManager() {
}

LTimerManager& LTimerManager::operator=(const LTimerManager& cpy) {
    if (this != &cpy) {
        actionval_ = cpy.actionval_;
        actionTime_ = cpy.actionTime_;
        listTime_ = cpy.listTime_;
    }
    return *this;
}

void LTimerManager::SetActualTime(const utime timestamps) {
    actionTime_ = timestamps;
    gettimeofday(&actionval_, 0);
}

utime LTimerManager::GetActualTime() const {
    utime ret = actionTime_;
    timeval actual;
    if (gettimeofday(&actual, 0) < 0)
        ret.valid = false;
    else
        ret.valid = true;
    timeval res;
    timersub(&actual, &actionval_, &res);
    addTime(ret, res);
    return ret;
}

const ITimerManager::timeHdl LTimerManager::setTimer() {
    timeval actual;
    if (gettimeofday(&actual, 0) < 0)
        return -1;
    listTime_.push_back(actual);
    return listTime_.size() - 1;
}

utime LTimerManager::GetTimeFrom(const ITimerManager::timeHdl& hdler) const {
    utime ret;
    timeval actual;

    if (isValid(hdler) && gettimeofday(&actual, 0) >= 0) {
        ret.valid = true;
        timeval res;
        timersub(&actual, &listTime_[hdler], &res);
        setTime(ret, res);
        return ret;
    }
    ret.valid = false;
    return ret;
}

inline bool LTimerManager::isValid(const ITimerManager::timeHdl& hdler) const {
    return hdler < listTime_.size();
}

utime LTimerManager::GetTimeBetween(const ITimerManager::timeHdl& hdl1, const ITimerManager::timeHdl& hdl2) const {
    utime ret;

    if (isValid(hdl1) && isValid(hdl2))
    {
        ret.valid = true;
        timeval res;
        timersub(&listTime_[hdl1], &listTime_[hdl2], &res);
        setTime(ret, res);
        return ret;
    }
    ret.valid = false;
    return ret;
}

utime LTimerManager::GetUnTimeBetween(const ITimerManager::timeHdl& hdl1, const ITimerManager::timeHdl& hdl2) const {
    utime ret;

    if (isValid(hdl1) && isValid(hdl2))
    {
        ret.valid = true;
        timeval res;
        if (hdl1 < hdl2)
            timersub(&listTime_[hdl2], &listTime_[hdl1], &res);
        else
            timersub(&listTime_[hdl1], &listTime_[hdl2], &res);
        setTime(ret, res);
        return ret;
    }
    ret.valid = false;
    return ret;
}

utime LTimerManager::GetTimeFromLast() const {
    utime ret;
    if (listTime_.empty())
    {
        ret.valid = false;
        return ret;
    }
    return GetTimeFrom(listTime_.size() - 1);
}

void LTimerManager::setTime(utime& ret, timeval& val) const {
    ret.sec = val.tv_sec;
    ret.usec = val.tv_usec;
}

void LTimerManager::addTime(utime& ret, timeval& val) const
{
    ret.sec += val.tv_sec;
    long int usec = ret.usec + val.tv_usec;
    ret.sec += usec / 1000000;
    ret.usec += usec % 1000000;
}