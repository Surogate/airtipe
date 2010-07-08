/*!
 * \file	IMutex.h
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
class		IMutex
{
	public:
		/*!
		 * \brief	blocking lock. wait until the mutex is free, and take the ressource
		 * \return	true if suceed. else false.
		 */
		virtual bool	lock() = 0;

		/*!
		 * \brief	non blocking lock. try to take control of the mutex. return false if the mutex is locked
		 * \return	true if control on ressource is taken. else false.
		 */
		virtual bool	trylock() = 0;

		/*!
		 * \brief	unlock the mutex (if you have control on it)
		 * \return	true if suceed. else false.
		 */
		virtual bool	unlock() = 0;
};

#endif		// IABSMUTEX_H__
