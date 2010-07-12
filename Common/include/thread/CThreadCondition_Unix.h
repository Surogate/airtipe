/*!
 * \file	CThreadCondition_Unix.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 15:18:45
 */

#ifndef		CTHREADCONDITION_H__
# define	CTHREADCONDITION_H__

#include	"thread/CMutex_Unix.h"
#include	"thread/IThreadCondition.h"

class		CThreadCondition_Unix
{
	public:
		CThreadCondition_Unix();
		virtual ~CThreadCondition_Unix();

	public:
		void	wait(Mutex& mutex);
		void	signal();
		void	broadcast();

	protected:
		pthread_cond_t		_cond;
};

typedef CThreadCondition_Unix	ThreadCondition;

#endif		// CTHREADCONDITION_H__
