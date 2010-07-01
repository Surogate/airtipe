/*!
 * \file	CAbsThread_Unix.h
 * \brief	Concrete implementation of thread absraction for UNIX
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	24/06/2010 13:11:44
 */

#ifndef		CABSTHREAD_UNIX_H__
# define	CABSTHREAD_UNIX_H__

#include	"pthread.h"
#include	"IAbsThread.h"

/*!
 * \brief	Concrete implementation of thread absraction for UNIX
 */
class		CAbsThread_Unix : public IAbsThread
{
	public:
		/*!
		 * \brief	Default constructor
		 */
		CAbsThread_Unix();

		/*!
		 * \brief	Destructor
		 */
		virtual		~CAbsThread_Unix();

	public:
		/*!
		 * \brief	Initialise the thread given in parameters
		 * \param	start		The routine from which the thread will start
		 * \param	args		Arguments for the start routine
		 */
		bool	launch(
					startRoutine	start,
					void*			args
				);

		/*!
		 * \brief	Wait for this thread to terminate
		 */
		virtual bool	join();

	private:
		/*!
		 * \brief	The identifier of the thread
		 */ 
		pthread_t		_tid;
};

/*!
 * \typedef	A typedef on the concrete implementation under UNIX to keep abstraction when used
 */
typedef CAbsThread_Unix		AbsThread;

#endif		// CABSTHREAD_UNIX_H__

