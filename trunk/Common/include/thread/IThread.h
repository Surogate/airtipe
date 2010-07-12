/*!
 * \file	IThread.h
 * \brief	Abstraction over threads
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	24/06/2010 12:34:06
 */

#ifndef		ITHREAD_H__
# define	ITHREAD_H__

/*!
 * \class	Interface defining an abstraction for portability for threads
 */
class		IThread
{
	public:
		virtual void	run() = 0;
		virtual bool	start(bool detached) = 0;
		virtual void	stop() = 0;
		virtual bool	create(bool detached) = 0;
		virtual void	join() = 0;
		virtual void	cancel() = 0;
};

#endif		// IABSTHREAD_H__
