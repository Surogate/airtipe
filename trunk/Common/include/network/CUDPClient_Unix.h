/*!
 * \file	CUDPClient_Unix.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	20/07/2010 15:09:42
 *
 * more description...
 */

#ifndef		CUDPCLIENT_UNIX_H__
# define	CUDPCLIENT_UNIX_H__

# include	<sys/socket.h>
# include	<arpa/inet.h>
# include	<netinet/in.h>
# include	"network/IUDPClient.h"
# include	"network/CUDPSession_Unix.h"

class		CUDPClient_Unix : public IUDPClient
{
	public:
		CUDPClient_Unix(std::string const & address, short port = 44547);
		virtual ~CUDPClient_Unix();

	public:
		bool	init();
		int		send(void* data, unsigned int size, bool safe = false);
		int		recv(void* data, unsigned int size);

	private:
		std::string		_serverAddress;
		short			_port;
		int				_socket;
		IUDPSession*	_server;
		IUDPSession*	_sender;
};

typedef	CUDPClient_Unix		UDPClient;

#endif		// CUDPCLIENT_UNIX_H__
