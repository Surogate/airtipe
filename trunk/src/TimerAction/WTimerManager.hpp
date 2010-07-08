/*!
 * \file    WTimerManager.hpp
 * \brief   Implementation of WTimerManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 5:52 PM
 */

#ifndef _WTIMERMANAGER_HPP
#define	_WTIMERMANAGER_HPP

#ifdef WIN32

# include <windows.h>
# include "ITimerManager.hpp"

class WTimerManager : public ITimerManager {
public:
    WTimerManager();
    WTimerManager(const WTimerManager& orig);
    virtual ~WTimerManager();
    WTimerManager & operator=(const WTimerManager&);

    void SetActualTime(const mtime timestamps);
    mtime GetActualTime() ;
    const timeHdl setTimer() ;
    mtime GetTimeFrom(const timeHdl& hdler) const;
    inline bool isValid(const timeHdl& hdler) const;
    mtime GetTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const;
    mtime GetUnTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const;
    mtime GetTimeFromLast() const;
    const bool good() const;

private:
    bool error;
    LARGE_INTEGER freq;
    mtime actionTime_;
    LARGE_INTEGER actionval_;
    std::vector<LARGE_INTEGER> listTime_;

    void setTime(mtime& ret, const double msec) const;
    void setTime(mtime& ret, const LARGE_INTEGER& val);
    void addTime(mtime& ret, const double msec);

};

#endif // WIN32


#endif	/* _WTIMERMANAGER_HPP */

