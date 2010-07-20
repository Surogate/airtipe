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
#include	"network/CUDPClient_Unix.h"

int		main()
{
	UDPClient	c("127.0.0.1");
	char*		wbuffer = "coucou";
	char*		rbuffer = new char[512];
	int			recv;

	if (c.init())
	{
		std::cout << "init ok" << std::endl;
		while (42)
		{
			c.send(wbuffer, 7);
			recv = c.recv(rbuffer, 512);
		}
	}
	return (0);
}

