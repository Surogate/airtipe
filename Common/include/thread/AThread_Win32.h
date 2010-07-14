/*!
 * \file	AThread_Win32.h
 * \brief	A specialized thread for ThreadPool class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 14:38:06
 */

#ifndef		ATHREAD_WIN32_H__
# define	ATHREAD_WIN32_H__

# include	<Windows.h>
# include "thread/IThread.h"

class		AThread_Win32 : public IThread
{
public:
	AThread_Win32();
	virtual ~AThread_Win32();

public:
	virtual void	run() = 0;
	virtual bool	start(bool detached);
	virtual void	stop();

public:
	bool	create(bool detached);
	void	join();
	void	cancel();

private:
	HANDLE	_tid;
	bool	_running;
};

typedef AThread_Win32 AThread;

#endif		// ATHREAD_WIN32_H__