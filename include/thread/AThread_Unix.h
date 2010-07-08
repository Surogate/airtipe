/*!
 * \file	AThread_Unix.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 12:49:33
 */

#ifndef		ATHREAD_UNIX_H__
# define	ATHREAD_UNIX_H__

# include	"pthread.h"
# include	"thread/IThread.h"

class		AThread_Unix : public IThread
{
	public:
		AThread_Unix();
		virtual ~AThread_Unix();

	public:
		virtual void	run() = 0;
		virtual bool	start(bool detached = false);
		virtual void	stop();

	public:
		bool	create(bool detached);
		void	join();
		void	cancel();

	private:
		pthread_t		_tid;
		pthread_attr_t	_tattr;
		bool			_running;
};

typedef AThread_Unix	AThread;

#endif		// ATHREAD_UNIX_H__
