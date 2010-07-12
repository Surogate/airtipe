/*!
 * \file	main.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 12:59:58
 */

#include	<iostream>

#ifdef		UNIX
# include	"thread/ThreadPool.h"
#endif

class	MyThread : public ATPTask
{
	public:
		void	run(void * arg)
		{
			int *i = static_cast<int*>(arg);
			std::cout << "coucou " << *i << std::endl;
		}
};

int		main()
{
	int i = 0;
	ThreadPool	pool(5);
	MyThread	th;

	while (42)
	{
		pool.run(&th, &i);
		i++;
	}
	return (0);
}
