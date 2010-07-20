/*!
 * \file	CUDPClient_Unix.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	20/07/2010 15:11:32
 *
 * more description...
 */

#include <iostream>
#include <fcntl.h>
#include <errno.h>
#include "network/CUDPClient_Unix.h"

CUDPClient_Unix::CUDPClient_Unix(std::string const & address, short port) :
	_serverAddress(address),
	_port(port),
	_socket(-1)
{

}

CUDPClient_Unix::~CUDPClient_Unix()
{

}

bool	CUDPClient_Unix::init()
{
	this->_socket = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (this->_socket == -1)
	{
		std::cerr << "socket failed" << std::endl;
		return (false);
	}
	fcntl(this->_socket, F_SETFL, O_NONBLOCK);
	this->_server = new UDPSession(this->_socket);
	this->_server->resetAddr();
	this->_server->getAddr().sin_family = AF_INET;
	this->_server->getAddr().sin_addr.s_addr = inet_addr(this->_serverAddress.c_str());
	this->_server->getAddr().sin_port = htons(this->_port);
	this->_sender = new UDPSession(this->_socket);
	return (true);
}

int		CUDPClient_Unix::send(void* data, unsigned int size, bool)
{
	return (this->_server->send(data, size));
}

int		CUDPClient_Unix::recv(void* data, unsigned int size)
{
	this->_sender->resetAddr();
	unsigned int addrSize = sizeof(this->_sender->getAddr());
	int received = recvfrom(
		this->_socket,
		data, size,
		0,
		(struct sockaddr*) &this->_sender->getAddr(),
		&addrSize
	);
	if (received == -1 && errno != EWOULDBLOCK)
		std::cerr << "recv failed" << std::endl;
	else if (received > 0)
	{
		if (*(this->_sender) == this->_server)
			std::cout << "received from server : " << std::string(static_cast<char*>(data), received) << std::endl;
		else
			std::cout << "received from unknown : " << std::string(static_cast<char*>(data), received) << std::endl;
	}
	return (received);
}

