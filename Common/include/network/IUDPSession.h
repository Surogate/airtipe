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
		virtual int		recv(unsigned int size) = 0;

	public:
		virtual void*	getData() = 0;
};

#endif		// IUDPSESSION_H__

