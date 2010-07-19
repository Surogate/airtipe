/*!
 * \file	CUDP_Unix.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	18/07/2010 19:23:02
 *
 * more description...
 */

#ifndef		CUDP_UNIX_H__
# define	CUDP_UNIX_H__

# include	<list>
# include	<sys/socket.h>
# include	<arpa/inet.h>
# include	<netinet/in.h>
# include	"network/IUDP.h"
# include	"network/CUDPSession_Unix.h"

class		CUDP_Unix : public IUDP
{
	public:
		CUDP_Unix(unsigned short port = 44547);
		virtual ~CUDP_Unix();

	public:
		bool	open();
		void	close();
		int		sendTo(void* data, unsigned int size);
		int		recvFrom(void* data, unsigned int size);

	private:
		unsigned short	_port;
		int				_socket;

	private:
		struct sockaddr_in		_addrMe;
		struct sockaddr_in		_addrClients;
		std::list<UDPSession*>	_clients;
};

typedef		CUDP_Unix	UDP;

#endif		// CUDP_UNIX_H__

