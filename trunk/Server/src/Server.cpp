/*!
 * \file	Server.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 20:00:43
 */

#include <sys/socket.h>
#include "Server.h"

Server::Server(short port, unsigned int bufferSize) :
	TCPServer(port, bufferSize)
{
	this->_actions.insert(std::pair<PacketCode, Action>(Login, &Server::ActionLogin));
	this->_actions.insert(std::pair<PacketCode, Action>(CreateGame, &Server::ActionCreateGame));

	this->_actions.insert(std::pair<PacketCode, Action>(AddMap, &Server::ActionAddMap));
	this->_actions.insert(std::pair<PacketCode, Action>(ValidGame, &Server::ActionValidGame));
	this->_actions.insert(std::pair<PacketCode, Action>(JoinGame, &Server::ActionJoinGame));
	this->_actions.insert(std::pair<PacketCode, Action>(ChooseSpacecraft, &Server::ActionChooseSpacecraft));
	this->_actions.insert(std::pair<PacketCode, Action>(Ready, &Server::ActionReady));
	this->_actions.insert(std::pair<PacketCode, Action>(NotReady, &Server::ActionNotReady));
	this->_actions.insert(std::pair<PacketCode, Action>(StartGame, &Server::ActionStartGame));
	this->_actions.insert(std::pair<PacketCode, Action>(StopGame, &Server::ActionStopGame));
	this->_actions.insert(std::pair<PacketCode, Action>(QuitGame, &Server::ActionQuitGame));
}

Server::~Server()
{

}

bool	Server::accept()
{
	struct sockaddr	saddr;
	unsigned int	saddrSize = sizeof(saddr);
	int newSock = ::accept(this->_socket, &saddr, &saddrSize);
	if (newSock >= 0)
	{
		this->_sessions.push_back(new Client(newSock));
		return (true);
	}
	return (false);
}

Packet *	Server::ActionLogin(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: Login" << std::endl;
	return NULL;
}


Packet *	Server::ActionCreateGame(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: CreateGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionAddMap(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: AddMap" << std::endl;
	return NULL;
}

Packet *	Server::ActionValidGame(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: ValidGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionJoinGame(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: JoinGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionChooseSpacecraft(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: ChooseSpacecraft" << std::endl;
	return NULL;
}

Packet *	Server::ActionReady(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: Ready" << std::endl;
	return NULL;
}

Packet *	Server::ActionNotReady(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: NotReady" << std::endl;
	return NULL;
}

Packet *	Server::ActionStartGame(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: StartGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionStopGame(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: StopGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionQuitGame(Packet * pak)
{
	pak = pak;
	std:: cout << "Action: QuitGame" << std::endl;
	return NULL;
}

