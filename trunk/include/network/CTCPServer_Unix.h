/*!
 * \file	CTCPServer_Unix.h
 * \brief	Concrete implementation of a TCP server for Unix
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 09:45:35
 */

#ifndef		CTCPSERVER_UNIX_H__
# define	CTCPSERVER_UNIX_H__

# include	<list>
# include	<sys/types.h>
# include	"network/ITCPServer.h"
# include	"network/CTCPSession_Unix.h"

/*!
 * \class	Concrete implementation of a TCP server for Unix
 */
class		CTCPServer_Unix : public ITCPServer
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

		virtual void		process();
		
		/*!
		 * \brief	Try accepting a new client (should be non blocking)
		 * \return	true if someone has been accepted. else false.
		 */
		virtual bool		accept();

		bool		poll();

		virtual void		readValidClients();

		virtual void		respondToValidClients();

		/*!
		 * \brief	Close the server and all opened client sessions
		 */
		void		close();

	public:
		void		DisplayError(std::string const & msg);
		void		DisplayNotice(std::string const & msg);
		void		DisplayWarning(std::string const & msg);

	protected:
		int		resetFdSets();

	protected:
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
		 * \brief	Determine if the server is running or not
		 */
		bool				_running;

		/*!
		 * \brief	A list of client sessions
		 */
		std::list<TCPSession*>		_sessions;

		std::list<std::pair<TCPSession*, void*> >		_in;
		std::list<std::pair<TCPSession*, Data*> >		_out;

		fd_set		_fdr;
		fd_set		_fdw;
};

/*!
 * \brief	A typedef to keep the abstraction at use
 */
typedef CTCPServer_Unix		TCPServer;

#endif		// CTCPSERVER_UNIX_H__
