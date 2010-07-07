/*!
 * \file	Server.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 20:00:43
 */

#include <sys/socket.h>
#include "Server.h"

Server::Server(short port, unsigned int bufferSize) :
	TCPServer(port, bufferSize)
{

}

Server::~Server()
{

}

bool	Server::accept()
{
	struct sockaddr	saddr;
	unsigned int	saddrSize = sizeof(saddr);
	int newSock = ::accept(this->_socket, &saddr, &saddrSize);
	if (newSock >= 0)
	{
		this->_sessions.push_back(new Client(newSock));
		return (true);
	}
	return (false);
}
