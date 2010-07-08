/*!
 * \file	ATPTask.h
 * \brief	A task for the ThreadPool class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 14:31:49
 */

#ifndef		ATPTASK_H__
# define	ATPTASK_H__

class TPThread;

class		ATPTask
{
	public:
		ATPTask();
		virtual ~ATPTask();

	public:
		virtual void	run(void *arg) = 0;

	public:
		TPThread*	getThread();
		void		setThread(TPThread* thread);

	protected:
		TPThread*	_thread;
};

#endif		// TPTASK_H__

