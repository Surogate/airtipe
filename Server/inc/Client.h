/*!
 * \file	Client.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 20:38:42
 */

#ifndef		CLIENT_H__
# define	CLIENT_H__

# ifdef		UNIX
#  include	"network/CTCPSession_Unix.h"
# endif

class		Client : public TCPSession
{
	public:
		#ifdef	UNIX
			Client(int socket);
		#endif
		virtual ~Client();
};

#endif		// CLIENT_H__
