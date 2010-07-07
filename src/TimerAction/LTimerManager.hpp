/*!
 * \file    LTimerManager.hpp
 * \brief   Implementation of LTimerManager class
 * \author  Francois Ancel - ancel_a@epitech.eu
 * \version 0.1
 * \date    July 7, 2010 5:52 PM
 */

#ifndef _LTIMERMANAGER_HPP
#define	_LTIMERMANAGER_HPP

# ifndef WIN32
# include "ITimerManager.hpp"
# include <sys/time.h>

class LTimerManager : public ITimerManager {
public:
    LTimerManager();
    LTimerManager(const LTimerManager& orig);
    virtual ~LTimerManager();
    LTimerManager & operator=(const LTimerManager&);

    void SetActualTime(const utime timestamps);
    utime GetActualTime() const;
    const timeHdl setTimer();
    utime GetTimeFrom(const timeHdl& hdler) const;
    inline bool isValid(const timeHdl& hdler) const;
    utime GetTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const;
    utime GetUnTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const;
    utime GetTimeFromLast() const;

private:
    utime actionTime_;
    timeval actionval_;
    std::vector<timeval> listTime_;

    void setTime(utime& ret, timeval& val) const;
    void addTime(utime& ret, timeval& val) const;
};

# endif // !WIN32


#endif	/* _LTIMERMANAGER_HPP */

