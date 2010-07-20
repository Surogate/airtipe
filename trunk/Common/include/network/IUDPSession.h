/*!
 * \file	IUDPSession.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	19/07/2010 16:16:42
 */

#ifndef		IUDPSESSION_H__
# define	IUDPSESSION_H__

class		IUDPSession
{
	public:
		virtual int		send(void* data, unsigned int size) = 0;
		virtual struct sockaddr_in&	getAddr() = 0;
		virtual void	resetAddr() = 0;
		virtual bool operator==(IUDPSession* session) = 0;
};

#endif		// IUDPSESSION_H__

