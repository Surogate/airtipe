/*!
 * \file    TimerManager.hpp
 * \brief   Implementation of TimerManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 2:58 PM
 */

#ifndef _TIMERMANAGER_HPP
#define	_TIMERMANAGER_HPP

#include "../functor/Functor.hpp"
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
    mtime(long int sec = 0, long int msec = 0);
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
    virtual void wait(const mtime& time) const = 0;

    template <typename Class, typename RetType, typename Param1, typename Param2>
    void waitTo(const mtime&, Functor<Class,RetType,Param1,Param2>&, Param1& arg1, Param2& arg2) const;
    template <typename Class, typename RetType, typename Param1>
    void waitTo(const mtime&, Functor<Class,RetType,Param1>&, Param1& arg1) const;
    template <typename Class, typename RetType>
    void waitTo(const mtime&, Functor<Class,RetType>&) const;

    static ITimerManager* AbsNew();
};

#endif	/* _TIMERMANAGER_HPP */
