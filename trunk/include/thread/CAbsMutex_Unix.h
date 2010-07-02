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
# include	"thread/IAbsMutex.h"

/*!
 * \class	Concrete implementation of mutex abstraction on Unix
 */
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
		 * \return	true if initialisation succeed. else false.
		 */
		bool	init();

		/*!
		 * \brief	to destroy the mutex
		 */
		void	destroy();

		/*!
		 * \brief	blocking lock. wait until the mutex is free, and take the ressource
		 * \return	should return true. return false if error.
		 */
		bool	lock();

		/*!
		 * \brief	non blocking lock. try to take control of the mutex.
		 * \return  return true if control on ressource is taken. return false if the mutex is locked
		 */
		bool	tryLock();

		/*!
		 * \brief	unlock the mutex (if you have control on it)
		 * \return	return true if succeed. else false.
		 */
		bool	unlock();

	private:
		/*!
		 * \brief	The mutex identifier
		 */
		pthread_mutex_t*	_mid;
};

/*!
 * \typedef		to keep abstraction in use
 */
typedef CAbsMutex_Unix	AbsMutex;

#endif		// CABSMUTEX_UNIX_H__
