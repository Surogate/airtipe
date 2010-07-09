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
		typedef Packet * (Server::*Action)(Client * client, Packet * pak);
		std::map<PacketCode, Action>	_actions;
		PacketManager	_pm;

	private:
		void		process();
		void		DisplayHeader(PacketHeader * header);
		bool		loginExists(std::string const & login);

	private:
		Packet *	ActionLogin(Client * client, Packet * pak);
		Packet *	ActionCreateGame(Client * client, Packet * pak);
		Packet *	ActionAddMap(Client * client, Packet * pak);
		Packet *	ActionValidGame(Client * client, Packet * pak);
		Packet *	ActionJoinGame(Client * client, Packet * pak);
		Packet *	ActionChooseSpacecraft(Client * client, Packet * pak);
		Packet *	ActionReady(Client * client, Packet * pak);
		Packet *	ActionNotReady(Client * client, Packet * pak);
		Packet *	ActionStartGame(Client * client, Packet * pak);
		Packet *	ActionStopGame(Client * client, Packet * pak);
		Packet *	ActionQuitGame(Client * client, Packet * pak);

};

#endif		// SERVER_H__
