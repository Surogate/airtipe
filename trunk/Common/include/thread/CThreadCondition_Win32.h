/*!
 * \file	CThreadCondition.h
 * \brief	A specialized thread for ThreadPool class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 14:38:06
 */

#ifndef		CTHREADCONDITION_WIN32_H__
# define	CTHREADCONDITION_WIN32_H__

# include "thread/IThreadCondition.h"
# include	"thread/CMutex_Win32.h"

class		CThreadCondition_Win32 : public IThreadCondition
{
public:
	CThreadCondition_Win32();
	virtual ~CThreadCondition_Win32();

public:
	void	wait(Mutex& mutex);
	void	signal();
	void	broadcast();

private:
	CONDITION_VARIABLE	_condition;
};

typedef CThreadCondition_Win32 ThreadCondition;

#endif		// CTHREADCONDITION_WIN32_H__