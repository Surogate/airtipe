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

    void SetActualTime(const mtime timestamps);
    mtime GetActualTime();
    const timeHdl setTimer();
    mtime GetTimeFrom(const timeHdl& hdler) const;
    inline bool isValid(const timeHdl& hdler) const;
    mtime GetTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const;
    mtime GetUnTimeBetween(const timeHdl& hdl1, const timeHdl& hdl2) const;
    mtime GetTimeFromLast() const;
    const bool good() const;
    void wait(const mtime& time) const;

private:
    bool error;
    mtime actionTime_;
    timeval actionval_;
    std::vector<timeval> listTime_;

    void setTime(mtime& ret, const timeval& val);
    void setTime(mtime& ret, const timeval& val) const;
    void addTime(mtime& ret, const timeval& val);
};

# endif // !WIN32


#endif	/* _LTIMERMANAGER_HPP */

