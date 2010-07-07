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

struct utime {
    long int sec;
    long int usec;
    bool valid;
    bool operator==(utime& comp);
    bool operator!=(utime& comp);
    utime& operator+(utime& comp);
    utime& operator-(utime& comp);
};

class ITimerManager {
public:
    typedef unsigned int timeHdl;
    
    virtual ~ITimerManager();
    virtual void SetActualTime(const utime timestamps) = 0; // modifie l'horloge interne
    virtual utime GetActualTime() const = 0;
    virtual const timeHdl setTimer() = 0;
    virtual utime GetTimeFrom(const timeHdl& hdler) const = 0;
    virtual inline bool isValid(const timeHdl& hdler) const = 0;
    virtual utime GetTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const = 0;
    virtual utime GetUnTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const = 0;
    virtual utime GetTimeFromLast() const = 0;
};

#endif	/* _TIMERMANAGER_HPP */
