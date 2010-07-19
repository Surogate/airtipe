/*!
 * \file	client.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	19/07/2010 18:56:04
 *
 * more description...
 */

#include	<iostream>
#include	"network/CUDP_Unix.h"

int		main()
{
	UDP	c(44547);
	char*	buffer = new char[512];

	if (c.open())
	{
		std::cout << "UDP opened" << std::endl;
		int msgSize;
		while (42)
		{
			msgSize = c.recvFrom(buffer, 512);
			if (msgSize > 0)
			{
				c.broadcast(buffer, msgSize);
			}
		}
		c.close();
		std::cout << "UDP closed" << std::endl;
	}

	delete [] buffer;
	return (0);
}

