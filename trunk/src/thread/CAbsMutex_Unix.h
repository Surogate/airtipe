/*!
 * \file	CAbsMutex_Unix.h
 * \brief	Definition of a concrete implementation of portability abstraction over mutexs under UNIX systems
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	01/07/2010 20:29:55
 */

#ifndef		CABSMUTEX_UNIX_H__
# define	CABSMUTEX_UNIX_H__

# include	"pthread.h"
# include	"IAbsMutex.h"

class		CAbsMutex_Unix : public IAbsMutex
{
	public:
		/*!
		 * \brief	Default constructor
		 */
		CAbsMutex_Unix();

		/*!
		 * \brief	Destructor
		 */
		virtual ~CAbsMutex_Unix();

	public:
		/*!
		 * \brief	initialisation of the mutex
		 */
		bool	init();

		/*!
		 * \brief	to destroy the mutex
		 */
		void	destroy();

		/*!
		 * \brief	blocking lock. wait until the mutex is free, and take the ressource
		 */
		bool	lock();

		/*!
		 * \brief	non blocking lock. try to take control of the mutex. return false if the mutex is locked
		 */
		bool	tryLock();

		/*!
		 * \brief	unlock the mutex (if you have control on it)
		 */
		bool	unlock();

	private:
		pthread_mutex_t*	_mid;
};

/*!
 * \typedef		to keep abstraction in use
 */
typedef CAbsMutex_Unix	AbsMutex;

#endif		// CABSMUTEX_UNIX_H__
