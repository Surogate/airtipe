/*!
 * \file	CTCPSession_Unix.cpp
 * \brief	Implementation of CTCPSession_Unix class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 11:24:22
 */

#include	<iostream>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	"network/CTCPSession_Unix.h"

CTCPSession_Unix::CTCPSession_Unix() :
	_socket(-1)
{

}

CTCPSession_Unix::CTCPSession_Unix(int socket) :
	_socket(socket)
{

}

CTCPSession_Unix::~CTCPSession_Unix()
{

}

int		CTCPSession_Unix::write(Data data, unsigned int size)
{
	return (-1);
}

int		CTCPSession_Unix::read(Data data, unsigned int size)
{
	return (-1);
}

bool	CTCPSession_Unix::close()
{
	if (this->_socket >= 0)
	{
		::close(this->_socket);
		return (true);
	}
	return (false);
}

int		CTCPSession_Unix::getSocket() const
{
	return (this->_socket);
}

