/*!
 * \file	TPThread.h
 * \brief	A specialized thread for ThreadPool class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 14:38:06
 */

#ifndef		TPTHREAD_H__
# define	TPTHREAD_H__

# ifdef		UNIX
#  include	"thread/AThread_Unix.h"
#  include	"thread/CMutex_Unix.h"
#  include	"thread/CThreadCondition_Unix.h"
# endif

class	ThreadPool;

# include	"thread/ATPTask.h"

class		TPThread : public AThread
{
	friend class ThreadPool;

	public:
		TPThread(ThreadPool* threadPool);
		virtual ~TPThread();

	public:
		void	run();

	public:
		void	setTask(ATPTask* task, void* data, bool destroy = false);

	protected:
		ThreadPool*		_threadPool;
		ATPTask*		_task;
		void*			_data;

	protected:
		bool	_working;
		bool	_end;
		bool	_destroy;

	protected:
		ThreadCondition	_workCondition;
		ThreadCondition	_syncCondition;

	protected:
		Mutex	_workMutex;
		Mutex	_syncMutex;
		Mutex	_taskMutex;
		Mutex	_deleteMutex;
};

#endif		// TPTHREAD_H__
