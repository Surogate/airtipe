/*!
 * \file	Client.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 20:43:46
 */

#include	"Client.h"

#ifdef		UNIX

Client::Client(int socket) :
	TCPSession(socket)
{

}

#endif // UNIX

Client::~Client()
{

}
