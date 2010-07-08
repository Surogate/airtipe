/*!
 * \file	Server.h
 * \brief	The central compoent of RType server. It manage all TCP requests
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 19:54:00
 */

#ifndef		SERVER_H__
# define	SERVER_H__

# include	<map>

# include	"Client.h"
# include	"packets/PacketManager.h"

# ifdef		UNIX
#  include	"network/CTCPServer_Unix.h"
# endif

/*!
 * \brief	The central compoent of RType server. It manage all TCP requests
 * It inherits from the concrete system implementation of TCPServer a redefine some functionnality:
 * - Uses Clients instead of TCPSession (also derived from TCPSession)
 * - Add 2 time read for Rtype packet functionnality
 * - obviously process in a smarter way clients requests
 */
class		Server : public TCPServer
{
	public:
		/*!
		 * \brief	Constructor
		 * \param	The port number to use for listen TCP clients
		 * \param	The maximum size of used buffers
		 */
		Server(short port, unsigned int bufferSize);

		/*!
		 * Destructor
		 */
		virtual ~Server();

	public:
		/*!
		 * \brief	redefinition of virtual method from TCPServer to mange Client instead of TCPSession
		 */
		bool	accept();

	private:
		typedef Packet * (Server::*Action)(Packet * pak);
		std::map<PacketCode, Action>	_actions;
		PacketManager	_pm;

	private:
		Packet *	ActionLogin(Packet * pak);
		Packet *	ActionCreateGame(Packet * pak);
		Packet *	ActionAddMap(Packet * pak);
		Packet *	ActionValidGame(Packet * pak);
		Packet *	ActionJoinGame(Packet * pak);
		Packet *	ActionChooseSpacecraft(Packet * pak);
		Packet *	ActionReady(Packet * pak);
		Packet *	ActionNotReady(Packet * pak);
		Packet *	ActionStartGame(Packet * pak);
		Packet *	ActionStopGame(Packet * pak);
		Packet *	ActionQuitGame(Packet * pak);
};

#endif		// SERVER_H__
