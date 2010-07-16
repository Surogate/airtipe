/*!
 * \file	TPThread.h
 * \brief	A specialized thread for ThreadPool class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 14:38:06
 */

#ifndef		CMUTEX_WIN32_H__
# define	CMUTEX_WIN32_H__

#ifdef WIN32

# include <Windows.h>
# include "thread/IMutex.h"

class		CMutex_Win32 : public IMutex
{
	friend class CThreadCondition_Win32;

public:
	CMutex_Win32();
	virtual ~CMutex_Win32();

public:
	bool lock();
	bool trylock();
	bool unlock();

private:
	CRITICAL_SECTION	_criticalSection;
};

typedef CMutex_Win32 Mutex;

#endif // !WIN32

#endif		// CTHREADCONDITION_WIN32_H__