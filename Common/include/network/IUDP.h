/*!
 * \file	IUDP.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	18/07/2010 19:16:54
 */

#ifndef		IUDP_H__
# define	IUDP_H__

# include	"IUDPSession.h"

class		IUDP
{
	public:
		virtual bool	open() = 0;
		virtual void	close() = 0;
		virtual void	broadcast(void* data, unsigned int size) = 0;
		virtual int		sendTo(IUDPSession* session, void* data, unsigned int size) = 0;
		virtual int		recvFrom(void* data, unsigned int size) = 0;
		virtual std::list<IUDPSession*>&	getSessions() = 0;
};

#endif		// IUDP_H__

