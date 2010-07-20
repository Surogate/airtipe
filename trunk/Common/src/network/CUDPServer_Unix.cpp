/*!
 * \file	CUDPServer_Unix.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	18/07/2010 19:25:13
 *
 * more description...
 */

#ifndef WIN32

#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <errno.h>
#include "network/CUDPServer_Unix.h"

CUDPServer_Unix::CUDPServer_Unix(unsigned short port) :
	_port(port),
	_socket(-1)
{
	memset(&this->_addrMe, 0, sizeof(this->_addrMe));
	this->_addrMe.sin_family = AF_INET;
	this->_addrMe.sin_addr.s_addr = htonl(INADDR_ANY);
	this->_addrMe.sin_port = htons(this->_port);
}

CUDPServer_Unix::~CUDPServer_Unix()
{

}

bool		CUDPServer_Unix::open()
{
	this->_socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (this->_socket == -1)
	{
		std::cerr << "socket failed" << std::endl;
		return (false);
	}
	fcntl(this->_socket, F_SETFL, O_NONBLOCK);
	int ret = bind(
			this->_socket,
			(struct sockaddr*) &this->_addrMe,
			sizeof(this->_addrMe)
	);
	if (ret == -1)
	{
		std::cerr << "bind failed" << std::endl;
		return (false);
	}
	return (true);
}

void	CUDPServer_Unix::close()
{

}

void	CUDPServer_Unix::broadcast(void* data, unsigned int size)
{
	std::list<IUDPSession*>::iterator it = this->_sessions.begin();
	std::list<IUDPSession*>::iterator ite = this->_sessions.end();
	while (it != ite)
	{
		(*it)->send(data, size);
		++it;
	}
}

int		CUDPServer_Unix::sendTo(IUDPSession* session, void* data, unsigned int size)
{
	return (session->send(data, size));
}

int		CUDPServer_Unix::recvFrom(void* data, unsigned int size)
{
	UDPSession*		session = new UDPSession(this->_socket);
	unsigned int addrSize = sizeof(session->getAddr());
	int received = recvfrom(
		this->_socket,
		data, size,
		0,
		(struct sockaddr*) &session->getAddr(),
		&addrSize
	);
	if (received == -1 && errno != EWOULDBLOCK)
		std::cerr << "recv failed" << std::endl;
	else if (received > 0)
	{
		if (!this->existSession(session))
		{
			this->_sessions.push_back(session);
			std::cout << "new session" << std::endl;
			return (received);
		}
		std::cout << "received : " << std::string(static_cast<char*>(data), received) << std::endl;
	}
	delete session;
	return (received);
}

std::list<IUDPSession*>&		CUDPServer_Unix::getSessions()
{
	return (this->_sessions);
}

bool	CUDPServer_Unix::existSession(IUDPSession* session)
{
	std::list<IUDPSession*>::iterator it = this->_sessions.begin();
	std::list<IUDPSession*>::iterator ite = this->_sessions.end();
	while (it != ite)
	{
		if (*(*it) == session)
			return (true);
		++it;
	}
	return (false);
}

#endif //!WIN32
