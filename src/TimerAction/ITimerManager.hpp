/*!
 * \file    TimerManager.hpp
 * \brief   Implementation of TimerManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 2:58 PM
 */

#ifndef _TIMERMANAGER_HPP
#define	_TIMERMANAGER_HPP

#include <ctime>
#include <time.h>
#include <vector>

struct mtime {
    long int sec;
    long int msec;
    bool valid;
    bool operator==(mtime& comp);
    bool operator!=(mtime& comp);
    mtime& operator+(mtime& comp);
    mtime& operator-(mtime& comp);
};

class ITimerManager {
public:
    typedef int timeHdl;
    
    virtual ~ITimerManager();
    virtual void SetActualTime(const mtime timestamps) = 0; // modifie l'horloge interne
    virtual mtime GetActualTime() = 0;
    virtual const timeHdl setTimer() = 0;
    virtual mtime GetTimeFrom(const timeHdl& hdler) const = 0;
    virtual inline bool isValid(const timeHdl& hdler) const = 0;
    virtual mtime GetTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const = 0;
    virtual mtime GetUnTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const = 0;
    virtual mtime GetTimeFromLast() const = 0;
    virtual const bool good() const = 0;
};

#endif	/* _TIMERMANAGER_HPP */
