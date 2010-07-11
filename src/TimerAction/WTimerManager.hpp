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
    mtime GetActualTime();
    const timeHdl setTimer() ;
    mtime GetTimeFrom(const timeHdl& hdler) const;
    inline bool isValid(const timeHdl& hdler) const;
    mtime GetTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const;
    mtime GetUnTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const;
    mtime GetTimeFromLast() const;
    const bool good() const;
    void wait(const mtime&) const;
    
private:
    bool error;
    mtime actionTime_;
    mtime actionval_;
    std::vector<mtime> listTime_;

    void getTime(mtime& ret);
    void getTime(mtime& ret) const;
    void setTime(mtime& ret, const _SYSTEMTIME& val);
    void setTime(mtime& ret, const _SYSTEMTIME& val) const;
};

#endif // WIN32


#endif	/* _WTIMERMANAGER_HPP */

