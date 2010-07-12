/*!
 * \file	ThreadPool.h
 * \brief	A pool of TPThread
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 14:50:01
 */

#ifndef		THREADPOOL_H__
# define	THREADPOOL_H__

# include	<list>
# include	<vector>
# include	"thread/TPThread.h"

class		ThreadPool
{
	public:
		ThreadPool(unsigned int maxThread = 5);
		virtual ~ThreadPool();

	public:
		void	run(ATPTask* task, void* data = NULL, bool destroy = false);
		void	sync(ATPTask* task);
		void	syncAll();

	public:
		TPThread*	getIdle();
		void		addIdle(TPThread* thread);

	protected:
		unsigned int				_maxThread;
		std::vector<TPThread*>		_threads;
		std::list<TPThread*>		_idleThreads;

	protected:
		Mutex				_idleMutex;
		Mutex				_idleListMutex;
};

#endif		// THREADPOOL_H__

