/*!
 * \file	TCPClient.hpp
 * \brief	TCPClient declaation
 * \author	Aurelien Lebrun - lebrun_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 22:30:45
 *
 * more description...
 */

#ifndef		_TCPCLIENT_HPP_
# define	_TCPCLIENT_HPP_

# include	<SFML/Network.hpp>
# include	<string>


class		TCPClient
{
	public:
		/*!
		 * \brief	Constructor
		 * Constructor of class TCPClient
		 */
		TCPClient();

		/*!
		 * \brief	Destructor
		 * Destructor of class TCPClient
		 */
		~TCPClient();

		void				connect(std::string address, unsigned short port);
		bool				failed();
		std::string 		receive();
		void				send(void * buf, unsigned int bufSize);

	private:
		sf::SocketTCP*		_client;
		sf::IPAddress		_serverAddress;
		unsigned short		_port;
		size_t				_received;
		bool				_fail;
};

#endif		/* _TCPCLIENT_HPP_ */

