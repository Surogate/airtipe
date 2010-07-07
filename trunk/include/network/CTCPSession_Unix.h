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
		CTCPSession_Unix(int socket);

		/*!
		 * \brief	Destructor
		 */
		virtual ~CTCPSession_Unix();

	public:
		/*!
		 * \brief	Write some data to the client owning the session
		 * \param	in: the data to write
		 * \param	size to write (in bytes)
		 * \return	the size wrote (in bytes). -1 if an error occured
		 */
		int		write(Data& data);

		/*!
		 * \brief	Read some data from the client owning the session
		 * \param	out: the buffer where the read data are wrote
		 * \paran	size to read (in bytes)
		 * \return	the size read (in bytes). -1 if an error occured
		 */
		int		read(Data& data);

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
}

/*!
 * \brief	A typedef to keep abstraction at use
 */
typedef CTCPSession_Unix		TCPSession;

#endif		// ITCPSESSION_H__
