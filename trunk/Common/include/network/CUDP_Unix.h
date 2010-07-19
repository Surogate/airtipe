/*!
 * \file	CUDP_Unix.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	18/07/2010 19:23:02
 *
 * more description...
 */

#ifndef WIN32
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
		void	broadcast(void* data, unsigned int size);
		int		sendTo(IUDPSession* session, void* data, unsigned int size);
		int		recvFrom(void* data, unsigned int size);

	public:
		std::list<IUDPSession*>&	getSessions();

	private:
		bool	existSession(IUDPSession* session);

	private:
		unsigned short	_port;
		int				_socket;

	private:
		struct sockaddr_in		_addrMe;
		std::list<IUDPSession*>	_sessions;
};

typedef		CUDP_Unix	UDP;

#endif		// CUDP_UNIX_H__

#endif //WIN32
