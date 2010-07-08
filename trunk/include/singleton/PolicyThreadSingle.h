/*!
 * \file	PolicyThreadSingle.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	06/07/2010 20:04:42
 */

#ifndef		POLICYTHREADSINGLE_H__
# define	POLICYTHREADSINGLE_H__

class		PolicyThreadSingle
{
	public:
		static void lock() {}
		static bool trylock() { return true; }
		static void unlock() {}
};

#endif		// POLICYTHREADSINGLE_H__
