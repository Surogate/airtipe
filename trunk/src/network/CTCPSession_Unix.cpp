/*!
 * \file	CTCPSession_Unix.cpp
 * \brief	Implementation of CTCPSession_Unix class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 11:24:22
 */

#include	<iostream>
#include	<cstdlib>
#include	<cstring>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	"network/CTCPSession_Unix.h"
#include	"network/CTCPServer_Unix.h"

CTCPSession_Unix::CTCPSession_Unix(int socket) :
	_socket(socket)
{
	fcntl(this->_socket, F_SETFL, O_NONBLOCK);
}

CTCPSession_Unix::~CTCPSession_Unix()
{
	this->close();
}

int		CTCPSession_Unix::write(Data& data)
{
	return (::write(this->_socket, data.data, data.size));
}

int		CTCPSession_Unix::read(Data& data)
{
	int res = ::read(this->_socket, data.data, data.size);
	if (res != 0)
	{
		data.size = res;
		return (res);
	}
	this->close();
	return (-1);
}

bool	CTCPSession_Unix::close()
{
	if (this->_socket >= 0)
	{
		::close(this->_socket);
		this->_socket = -1;
		return (true);
	}
	return (false);
}

int		CTCPSession_Unix::getSocket() const
{
	return (this->_socket);
}

