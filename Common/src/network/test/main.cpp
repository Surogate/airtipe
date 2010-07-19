/*!
 * \file	main.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	18/07/2010 18:51:29
 */

#include	<iostream>
#include	"network/CUDP_Unix.h"

int		main()
{
	UDP	s;
	char*	buffer = new char[512];

	if (s.open())
	{
		std::cout << "UDP opened" << std::endl;
		int msgSize;
		while (42)
		{
			//std::cout << "loop" << std::endl;
			msgSize = s.recvFrom(buffer, 512);
			if (msgSize > 0)
				s.sendTo(buffer, msgSize);
		}
		s.close();
		std::cout << "UDP closed" << std::endl;
	}

	delete [] buffer;
	return (0);
}

