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

void	Server::readValidClients()
{
	std::list<TCPSession*>::iterator	it = this->_sessions.begin();
	while (it != this->_sessions.end())
	{
		if (FD_ISSET((*it)->getSocket(), &this->_fdr))
		{
			Data*	headerData = new Data(sizeof(PacketHeader));
			int res = (*it)->read(*headerData);
			if (res != -1)
			{
				PacketHeader *	header = new (headerData->data) PacketHeader;
				std::cout << "[RECV] code:" << header->code << " timestamp:" << header->timestamp << " datasize:" << header->dataSize << std::endl;
				if (header->dataSize > 0)
				{
					Data *		packetData = new Data(header->dataSize);
					res = (*it)->read(*packetData);
					if (res != -1)
					{
						AData * data = (AData *) packetData->data;
						this->Exec(new Packet(header, data));
					}
					delete packetData;
				}
			}
			else
			{
				std::cout << "client disconnected" << std::endl;
				it = this->_sessions.erase(it);
				return;
			}
		}
		++it;
	}
}

void		Server::Exec(Packet * pak)
{
	std::map<PacketCode, Action>::const_iterator	it = this->_actions.begin();
	std::map<PacketCode, Action>::const_iterator	ite = this->_actions.end();

	while (it != ite)
	{
		if (it->first == pak->header->code)
		{
			(this->*(it->second))(pak);
			return;
		}
		++it;
	}
}

Packet *	Server::ActionLogin(Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std:: cout << "Action: Login" << std::endl;
	std::cout << "Id: " << data->id << std::endl;
	std::cout << "login: " << data->login << std::endl;
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

