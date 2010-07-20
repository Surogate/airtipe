/*!
 * \file	CUDPSession_Unix.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	19/07/2010 16:19:58
 */

#include <cstring>
#include <iostream>
#include "network/CUDPSession_Unix.h"

CUDPSession_Unix::CUDPSession_Unix(int socket) :
	_socket(socket)
{

}

CUDPSession_Unix::~CUDPSession_Unix()
{

}

int		CUDPSession_Unix::send(void* data, unsigned int size)
{
	int ret = sendto(
		this->_socket,
		data, size,
		0,
		(struct sockaddr*) &this->_addr,
		sizeof(this->_addr)
	);
	if (ret == -1)
		std::cerr << "send failed" << std::endl;
	else if (ret != static_cast<int>(size))
		std::cerr << "message not totally sent" << std::endl;
	else
		std::cout << "sending  : " << std::string(static_cast<char*>(data), size) << std::endl;
	return (ret);
}

struct sockaddr_in&		CUDPSession_Unix::getAddr()
{
	return this->_addr;
}

void					CUDPSession_Unix::resetAddr()
{
	memset(&this->_addr, 0, sizeof(this->_addr));
}

bool CUDPSession_Unix::operator==(IUDPSession* session)
{
	int ret = memcmp(&this->_addr, &session->getAddr(), sizeof(this->_addr));
	if (ret == 0)
		return (true);
	return (false);
}

