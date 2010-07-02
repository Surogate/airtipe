/*!
 * \file	CTCPServer_Unix.h
 * \brief	Concrete implementation of a TCP server for Unix
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 09:45:35
 */

#ifndef		CTCPSERVER_UNIX_H__
# define	CTCPSERVER_UNIX_H__

# include	<map>
# include	<list>
# include	"network/ITCPServer.h"
# include	"network/CTCPSession_Unix.h"
# include	"thread/CAbsThread_Unix.h"
# include	"thread/CAbsMutex_Unix.h"

/*!
 * \class	Concrete implementation of a TCP server for Unix
 */
class		CTCPServer_Unix : ITCPServer
{
	public:
		/*!
		 * \brief	Default constructor
		 */
		CTCPServer_Unix(short port);

		/*!
		 * \brief	Destructor
		 */
		virtual ~CTCPServer_Unix();

	public:
		/*!
		 * \brief	creation of the socket and initialisation
		 * \return	true if the socket is correctly initialise. else false.
		 */
		bool			init();

		/*!
		 * \brief	The main method to run the server
		 */
		virtual void	run();

		/*!
		 * \brief	Abstraction for demultiplexing clients (sessions)
		 * \return	The total changes number
		 */
		int			poll();

		/*!
		 * \brief	Try accepting a new client (should be non blocking)
		 * \return	true if someone has been accepted. else false.
		 */
		bool		accept();

		/*!
		 * \brief	Close the server and all opened client sessions
		 */
		void		close();

	private:
		/*!
		 * \brief	The server port
		 */
		short				_port;

		/*!
		 * \brief	The listening socket
		 */
		int					_socket;

		/*!
		 * \brief	Determine if the server is runnig or not
		 */
		bool				_running;

		/*!
		 * \brief	A list of client sessions
		 */
		std::map<TCPSession*, AbsThread*>		_sessions;

		/*!
		 * \brief	A list of clients requests (need a mutex for access)
		 */
		std::map<TCPSession*, Data>				_requests;

		/*!
		 * \brief	Mutex for requests
		 */
		AbsMutex		_mutexRequests;
};

/*!
 * \brief	A typedef to keep the abstraction at use
 */
typedef CTCPServer_Unix		TCPServer;

#endif		// CTCPSERVER_UNIX_H__
