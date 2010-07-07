/*!
 * \file	Server.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 19:54:00
 */

#ifndef		SERVER_H__
# define	SERVER_H__

#ifdef		UNIX
# include	"network/CTCPServer_Unix.h"
#endif

class		Server : public TCPServer
{
	public:
		Server(short port, unsigned int bufferSize);
		virtual ~Server();
};

#endif		// SERVER_H__
