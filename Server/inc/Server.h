/*!
 * \file	Server.h
 * \brief	
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

class		Server : public TCPServer
{
	public:
		Server(short port, unsigned int bufferSize);
		virtual	~Server();

	public:
		bool	accept();
		void	readValidClients();

	private:
		typedef Packet * (Server::*Action)(Packet * pak);
		std::map<PacketCode, Action>	_actions;
		PacketManager	_pm;

	private:
		void		process();
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
