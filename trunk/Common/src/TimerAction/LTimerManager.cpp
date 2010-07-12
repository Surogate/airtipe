/*!
 * \file    LTimerManager.cpp
 * \brief   Implementation of LTimerManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 5:52 PM
 */

#include "LTimerManager.hpp"

#ifndef WIN32

#include <unistd.h>

LTimerManager::LTimerManager()
: error(false) {
    listTime_.clear();
    if (gettimeofday(&actionval_, 0) < 0)
        error = true;
    setTime(actionTime_, actionval_);
}

LTimerManager::LTimerManager(const LTimerManager& cpy)
: actionval_(cpy.actionval_), actionTime_(cpy.actionTime_), listTime_(cpy.listTime_), error(cpy.error) {
}

LTimerManager::~LTimerManager() {
}

LTimerManager& LTimerManager::operator=(const LTimerManager& cpy) {
    if (this != &cpy) {
        actionval_ = cpy.actionval_;
        actionTime_ = cpy.actionTime_;
        listTime_ = cpy.listTime_;
        error = cpy.error;
    }
    return *this;
}

void LTimerManager::SetActualTime(const mtime timestamps) {
    actionTime_ = timestamps;
    if (gettimeofday(&actionval_, 0) < 0)
        error = true;
}

mtime LTimerManager::GetActualTime() {
    mtime ret = actionTime_;
    timeval actual;
    if (gettimeofday(&actual, 0) < 0) {
        ret.valid = false;
        return ret;
    } else
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

mtime LTimerManager::GetTimeFrom(const ITimerManager::timeHdl& hdler) const {
    mtime ret;
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

mtime LTimerManager::GetTimeBetween(const ITimerManager::timeHdl& hdl1, const ITimerManager::timeHdl& hdl2) const {
    mtime ret;

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

mtime LTimerManager::GetUnTimeBetween(const ITimerManager::timeHdl& hdl1, const ITimerManager::timeHdl& hdl2) const {
    mtime ret;

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

mtime LTimerManager::GetTimeFromLast() const {
    mtime ret;
    if (listTime_.empty())
    {
        ret.valid = false;
        return ret;
    }
    return GetTimeFrom(listTime_.size() - 1);
}

const bool LTimerManager::good() const {
    return !error;
}

void LTimerManager::wait(const mtime& time) const {
    usleep((time.sec * 1000000) + (time.msec * 1000));
}

void LTimerManager::setTime(mtime& ret, const timeval& val) {
    ret.sec = val.tv_sec;
    ret.msec = val.tv_usec / 1000;
}

void LTimerManager::setTime(mtime& ret, const timeval& val) const {
    ret.sec = val.tv_sec;
    ret.msec = val.tv_usec / 1000;
}

void LTimerManager::addTime(mtime& ret, const timeval& val) {
    ret.sec += val.tv_sec;
    long int usec = ret.msec * 1000 + val.tv_usec;
    ret.sec += usec / 1000000;
    ret.msec += (usec % 1000000) / 1000;
}

#endif //WIN32
