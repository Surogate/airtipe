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
		 * \brief	Constructor
		 * \param	The port on which the server will listen
		 * \param	Size for read buffers
		 */
		CTCPServer_Unix(short port,  unsigned int bufferSize);

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
		 * \brief	Try accepting a new client (should be non blocking)
		 * \return	true if someone has been accepted. else false.
		 */
		bool		accept();

		/*!
		 * \brief	The function to redefine to do something with data incoming from clients threads
		 */
		virtual void		processData();

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

		/*
		 * \brief	Size for read buffers
		 */
		unsigned int		_bufferSize;

		/*!
		 * \brief	Determine if the server is runnig or not
		 */
		bool				_running;

		/*!
		 * \brief	A list of client sessions
		 */
		std::map<TCPSession*, AbsThread*>		_sessions;

	public:
		/*!
		 * \brief	A list of clients requests (need a mutex for access)
		 */
		std::list<std::pair<TCPSession*, Data> >	requests;

		/*!
		 * \brief	Mutex for requests
		 */
		AbsMutex		mutexRequests;
};

/*!
 * \brief	A typedef to keep the abstraction at use
 */
typedef CTCPServer_Unix		TCPServer;

#endif		// CTCPSERVER_UNIX_H__
