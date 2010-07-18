/*!
 * \file	CUDP_Unix.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	18/07/2010 19:25:13
 *
 * more description...
 */

#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <errno.h>
#include "network/CUDP_Unix.h"

CUDP_Unix::CUDP_Unix(unsigned short port) :
	_port(port),
	_socket(-1)
{
	memset(&this->_addrMe, 0, sizeof(this->_addrMe));
	this->_addrMe.sin_family = AF_INET;
	this->_addrMe.sin_addr.s_addr = htonl(INADDR_ANY);
	this->_addrMe.sin_port = htons(this->_port);
}

CUDP_Unix::~CUDP_Unix()
{

}

bool		CUDP_Unix::open()
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

void	CUDP_Unix::close()
{

}

int		CUDP_Unix::sendTo(void* data, unsigned int size)
{
	std::cout << "sending  : " << std::string(static_cast<char*>(data), size) << std::endl;
	int ret = sendto(
		this->_socket,
		data, size,
		0,
		(struct sockaddr*) &this->_addrClients,
		sizeof(this->_addrClients)
	);
	if (ret == -1)
		std::cerr << "send failed" << std::endl;
	else if (ret != static_cast<int>(size))
		std::cerr << "message not totally sent" << std::endl;
	else
		std::cout << "sending  : " << std::string(static_cast<char*>(data), size) << std::endl;
	return (ret);
}

int		CUDP_Unix::recvFrom(void* data, unsigned int size)
{
	unsigned int addrSize = sizeof(this->_addrClients);
	int received = recvfrom(
		this->_socket,
		data, size,
		0,
		(struct sockaddr*) &this->_addrClients,
		&addrSize
	);
	if (received == -1 && errno != EWOULDBLOCK)
		std::cerr << "recv failed" << std::endl;
	else if (received > 0)
	{
		std::cout << "received : " << std::string(static_cast<char*>(data), received) << std::endl;
	}
	return (received);
}

