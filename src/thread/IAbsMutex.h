/*!
 * \file	IAbsMutex.h
 * \brief	Interface over shared ressources between threads (mutex)
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	01/07/2010 20:19:46
 */

#ifndef		IABSMUTEX_H__
# define	IABSMUTEX_H__

/*!
 * \class	Interface over shared ressources between threads (mutex)
 */
class		IAbsMutex
{
	public:
		/*!
		 * \brief	initialisation of the mutex
		 */
		virtual bool	init() = 0;

		/*!
		 * \brief	to destroy the mutex
		 */
		virtual void	destroy() = 0;

		/*!
		 * \brief	blocking lock. wait until the mutex is free, and take the ressource
		 */
		virtual bool	lock() = 0;

		/*!
		 * \brief	non blocking lock. try to take control of the mutex. return false if the mutex is locked
		 */
		virtual bool	tryLock() = 0;

		/*!
		 * \brief	unlock the mutex (if you have control on it)
		 */
		virtual bool	unlock() = 0;
};

#endif		// IABSMUTEX_H__
