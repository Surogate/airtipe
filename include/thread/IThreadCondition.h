/*!
 * \file	IThreadCondition.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 15:15:17
 */

#ifndef		ITHREADCONDITION_H__
# define	ITHREADCONDITION_H__

class		IThreadCondition
{
	public:
		virtual void	wait(Mutex& mutex);
		virtual void	signal();
		virtual void	broadcast();
};

#endif		// ITHREADCONDITION_H__
