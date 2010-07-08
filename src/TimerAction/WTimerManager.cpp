/*!
 * \file    WTimerManager.cpp
 * \brief   Implementation of WTimerManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 5:52 PM
 */

#ifdef WIN32

# include <cmath>
# include "WTimerManager.hpp"

WTimerManager::WTimerManager() {
    QueryPerformanceCounter(&freq);
    if (!QueryPerformanceCounter(&actionval_))
        error = true;
    setTime(actionTime_, actionval_);
    listTime_.clear();
}

WTimerManager::WTimerManager(const WTimerManager& orig)
: freq(orig.freq), actionTime_(orig.actionTime_), actionval_(orig.actionval_), listTime_(orig.listTime_) {
}

WTimerManager::~WTimerManager() {
}

void WTimerManager::SetActualTime(const mtime timestamps) {
    actionTime_ = timestamps;
    if (!QueryPerformanceCounter(&actionval_))
        error = true;
}

mtime WTimerManager::GetActualTime() {
    mtime ret = actionTime_;
    LARGE_INTEGER actual;
    if (!QueryPerformanceCounter(&actual)) {
        ret.valid = false;
        return ret;
    } else
        ret.valid = true;
    double diff = (actual.QuadPart - actionval_.QuadPart) * 1000.0 / freq.QuadPart;
    addTime(ret, diff);
    return ret;
}

const ITimerManager::timeHdl WTimerManager::setTimer() {
    LARGE_INTEGER actual;
    if (!QueryPerformanceCounter(&actual))
        return -1;
    listTime_.push_back(actual);
    return listTime_.size() -1;
}

mtime WTimerManager::GetTimeFrom(const timeHdl& hdler) const {
    mtime ret;
    LARGE_INTEGER actual;
    if (isValid(hdler) && QueryPerformanceCounter(&actual)){
        double diff = (actual.QuadPart - listTime_[hdler].QuadPart) * 1000.0 / freq.QuadPart;
        ret.valid = true;
        setTime(ret, diff);
        return ret;
    }
    ret.valid = false;
    return ret;
}

inline bool WTimerManager::isValid(const ITimerManager::timeHdl& hdler) const {
    return (hdler < listTime_.size());
}

mtime WTimerManager::GetTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const {
    mtime ret;

    if (isValid(hdl1) && isValid(hdl2))
    {
        double diff = (listTime_[hdl1].QuadPart - listTime_[hdl2].QuadPart) * 1000.0 / freq.QuadPart;
        ret.valid = true;
        setTime(ret, diff);
        return ret;
    }
    ret.valid = false;
    return ret;
}

mtime WTimerManager::GetUnTimeBetween(const ITimerManager::timeHdl& hdl1, const ITimerManager::timeHdl& hdl2) const {
    mtime ret;

    if (isValid(hdl1) && isValid(hdl2))
    {
        ret.valid = true;
        double diff;
        if (hdl1 < hdl2)
            diff = (listTime_[hdl1].QuadPart - listTime_[hdl2].QuadPart) * 1000.0 / freq.QuadPart;
        else
            diff = (listTime_[hdl2].QuadPart - listTime_[hdl1].QuadPart) * 1000.0 / freq.QuadPart;
        setTime(ret, diff);
        return ret;
    }
    ret.valid = false;
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

const bool WTimerManager::good() const
{
    return !error;
}

void WTimerManager::setTime(mtime& ret, const LARGE_INTEGER& val) {
    ret.msec = val.QuadPart * 1000 / freq.QuadPart;
    ret.sec = ret.msec / 1000;
    ret.msec = ret.msec % 1000;
}

void WTimerManager::setTime(mtime& ret, const double msec) const {
    ret.msec = (long int)msec;
    ret.sec = ret.msec / 1000;
    ret.msec = ret.msec % 1000;
}

void WTimerManager::addTime(mtime& ret, const double msec) {
    ret.msec += (long int)msec;
    ret.sec += ret.msec / 1000;
    ret.msec = ret.msec % 1000;
}

#endif // WIN32
