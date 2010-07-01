/*!
 * \file	IAbsThread.h
 * \brief	Abstraction over threads
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	24/06/2010 12:34:06
 */

#ifndef		IABSTHREAD_H__
# define	IABSTHREAD_H__

/*!
 * \typedef	The prototype of a routine for threads to start from
 */
typedef void*	(*startRoutine)(void*);

/* 
 * \typedef	The thread identifier, to manipulate it after creation
 */
typedef void*	threadID;

/*!
 * \class	Interface defining an abstraction for portability for threads
 */
class		IAbsThread
{
	public:
		/*!
		 * \brief	Initialise the thread given in parameters
		 * \param	threadID	The new thread to initialize
		 * \param	start		The routine from which the thread will start
		 * \param	args		Arguments for the start routine
		 */
		virtual bool	launch(
							startRoutine	start,
							void*			args
						) = 0;

		/*!
		 * \brief	Wait for this thread to terminate
		 */
		virtual bool	join() = 0;
};

#endif		// IABSTHREAD_H__
