/*!
 * \file	IUDPClient.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	20/07/2010 15:08:08
 *
 * more description...
 */

#ifndef		IUDPCLIENT_H__
# define	IUDPCLIENT_H__

class		IUDPClient
{
	public:
		virtual bool	init() = 0;
		virtual int		send(void* data, unsigned int size, bool safe) = 0;
		virtual int		recv(void* data, unsigned int size) = 0;
};

#endif		// IUDPCLIENT_H__
