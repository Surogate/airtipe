/*!
 * \file	ITCPServer.h
 * \brief	Abstratction for synchronous TCP server
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 09:39:01
 */

#ifndef		ITCPSERVER_H__
# define	ITCPSERVER_H__

# include	"network/TCPData.h"
typedef TCPData Data;

/*!
 * \class	Abstraction for sychronous TCP server
 */
class		ITCPServer
{
	public:
		/*!
		 * \brief	Initiate useful composant (ex: Winsock)
		 * \return	true if the initialisation succeed. else false.
		 */
		virtual bool	init() = 0;

		/*!
		 * \brief	The main method to run the server
		 */
		virtual void	run() = 0;

		virtual bool	poll() = 0;

		virtual void	process() = 0;
		/*!
		 * \brief	Try accepting a new client (should be non blocking)
		 * \return	true if a new client has been accepted. else false
		 */
		virtual bool	accept() = 0;

		/*!
		 * \brief	Close the server and all opened client sessions
		 */
		virtual void	close() = 0;
};

#endif		// ITCPSERVER_H__

