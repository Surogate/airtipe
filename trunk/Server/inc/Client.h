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

/*!
 * \brief	Handler and enhancer specialized for RType above TCPSession (used in TCPServer)
 * It is only for RType use, and is destined to be used by the RType Server class.
 * It allow this server to read RType packets from players
 */
class		Client : public TCPSession
{
	public:
		/*!
		 * Constructor (Changes between Unix and Win32 implementations
		 */
		#ifdef	UNIX
			Client(int socket);
		#endif

		/*!
		 * \brief	Destructor
		 */
		virtual ~Client();
};

#endif		// CLIENT_H__
