/*!
 * \file	main.cpp
 * \brief	Test main for myThreads
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	24/06/2010 12:30:00
 */

#ifdef		UNIX
# include "CAbsThread_Unix.h"
# include "CAbsMutex_Unix.h"
#endif

#include	<iostream>
#include	<cstdlib>

AbsMutex	gl_mutex;
int			gl_val = 0;

void*	myThread(void* data)
{
	int*	idata = static_cast<int*>(data);
	int i = -1;
	while (i < 10)
	{
		// if (gl_mutex.lock())
		if (gl_mutex.tryLock())
		{
			if (gl_val > i)
			{
				gl_val++;
				std::cout << "thread:" << *idata << "\t" << gl_val << std::endl;
				i = gl_val;
			}
			gl_mutex.unlock();
		}
	}
	exit(EXIT_SUCCESS);
}

int		main()
{
	gl_mutex.init();

	int data1;
	int data2;

	AbsThread	t1;
	data1 = 1;
	t1.launch(&myThread, &data1);

	AbsThread	t2;
	data2 = 2;
	t2.launch(&myThread, &data2);

	t1.join();
	t2.join();

	gl_mutex.destroy();

	return (0);
}
