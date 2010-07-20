/*!
 * \file	IUDPServer.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	18/07/2010 19:16:54
 */

#ifndef		IUDPSERVER_H__
# define	IUDPSERVER_H__

# include	"IUDPSession.h"

class		IUDPServer
{
	public:
		virtual bool	open() = 0;
		virtual void	close() = 0;
		virtual void	broadcast(void* data, unsigned int size) = 0;
		virtual int		sendTo(IUDPSession* session, void* data, unsigned int size) = 0;
		virtual int		recvFrom(void* data, unsigned int size) = 0;
		virtual std::list<IUDPSession*>&	getSessions() = 0;
};

#endif		// IUDPSERVER_H__

