/*!
 * \file	main.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 19:49:17
 */

#include	<iostream>
#include	"Server.h"

int		main()
{
	Server	server(22255, 16);

	if (server.init())
	{
		std::cout << "Server listening" << std::endl;
		server.run();
	}
	return (0);
}
