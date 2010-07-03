/*!
 * \file	CTCPSession_Unix.h
 * \brief	Concrete implementation of a TCP session for Unix
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 11:25:07
 */

#ifndef		CTCPSESSION_UNIX_H__
# define	CTCPSESSION_UNIX_H__

#include	<list>
#include	"network/ITCPSession.h"
#include	"thread/CAbsMutex_Unix.h"

class		CTCPServer_Unix;
typedef		CTCPServer_Unix		TCPServer;

/*!
 * \brief	Concrete implementation of a TCP session for Unix
 */
class		CTCPSession_Unix : ITCPSession
{
	public:
		/*!
		 * \brief	Constructor with socket initialisation
		 * \param	The socket to init with
		 * \param	A reference to the server which own the session
		 * \param	Size of read buffers
		 */
		CTCPSession_Unix(int socket, TCPServer& server, unsigned int bufferSize = 512);

		/*!
		 * \brief	Destructor
		 */
		virtual ~CTCPSession_Unix();

	public:
		/*!
		 * \brief	To run the sesssion
		 */
		virtual void	run();

		/*!
		 * \brief	To demultiplex data on the socket (use select)
		 * \return	true if there is something to do. else false.
		 */
		bool		poll();

		/*!
		 * \brief	Write some data to the client owning the session
		 * \param	in: the data to write
		 * \param	size to write (in bytes)
		 * \return	the size wrote (in bytes). -1 if an error occured
		 */
		int		write(Data data, unsigned int size);

		/*!
		 * \brief	Read some data from the client owning the session
		 * \param	out: the buffer where the read data are wrote
		 * \paran	size to read (in bytes)
		 * \return	the size read (in bytes). -1 if an error occured
		 */
		int		read(Data data, unsigned int size);

		/*!
		 * \brief	Close the session
		 * \return	true if the sessions is correctly close. else false.
		 */
		bool	close();

	public:
		/*!
		 * \brief	Getter for _socket member
		 * \return	the socket file descriptor
		 */
		int		getSocket() const;

	private:
		/*!
		 * \brief	The client socket
		 */
		int		_socket;

		/*!
		 * \brief	A reference to the server
		 */
		TCPServer&	_server;

		/*!
		 * \brief	Size of buffers for reads
		 */
		unsigned int	_bufferSize;

		/*!
		 * \brief	Incoming data
		 */
		std::list<Data>		_incoming;

		/*!
		 * \brief	A bool to tell us when the client socket is disconnected or broken
		 */
		bool	_broken;

		/*!
		 * \brief	Set to true if there is data incoming on socket. Call poll
		 */
		bool	_canRead;

		/*!
		 * \brief	Set to true if socket is ready to be written. Call poll
		 */
		bool	_canWrite;
	
	public:
		/*!
		 * \brief	Outgoing data
		 */
		std::list<Data>		outgoing;

		/*!
		 * \brief	mutex on outgoing data
		 */
		AbsMutex			mutexOutgoing;
};

/*!
 * \brief	A typedef to keep abstraction at use
 */
typedef CTCPSession_Unix		TCPSession;

#endif		// ITCPSESSION_H__
