/*!
 * \file	CUDPSession_Unix.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	19/07/2010 16:16:26
 */

#ifndef		CUDPSESSION__UNIX_H__
# define	CUDPSESSION__UNIX_H__

# include	<sys/socket.h>
# include	<arpa/inet.h>
# include	<netinet/in.h>
# include	"network/IUDPSession.h"

class		CUDPSession_Unix : public IUDPSession
{
	public:
		CUDPSession_Unix(int socket);
		virtual ~CUDPSession_Unix();
		bool operator==(IUDPSession* session);

	public:
		int		send(void* data, unsigned int size);

	public:
		struct sockaddr_in&		getAddr();

	private:
		int						_socket;
		struct sockaddr_in		_addr;
};

typedef CUDPSession_Unix	UDPSession;

#endif		// CUDPSESSION_H__

