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
	int									res = 0;

	while (it != this->_sessions.end())
	{
		if (FD_ISSET((*it)->getSocket(), &this->_fdr))
		{
			Data*	headerData = new Data(sizeof(PacketHeader));
			res = (*it)->read(*headerData);
			if (res != -1)
			{
				if (res == sizeof(PacketHeader))
				{
					PacketHeader *	header = new (headerData->data) PacketHeader;
					std::cerr << "[RECV] code:" << header->code
						<< " timestamp:" << header->timestamp
						<< " datasize:" << header->dataSize
						<< std::endl;
					if (header->dataSize > 0 && header->dataSize < 1000)
					{
						Data *		packetData = new Data(header->dataSize);
						res = (*it)->read(*packetData);
						if (res != -1)
						{
							if (res == header->dataSize)
							{
								AData * data = (AData *) packetData->data;
								this->_in.push_back(std::pair<TCPSession*, void*>(*it, new Packet(header, data)));
							}
							else
								std::cerr << "[ERROR] Packet broken" << std::endl;
						}
						else
						{
							std::cerr << "client disconnected" << std::endl;
							this->_sessions.erase(it);
							return;
						}
						delete packetData;
					}
				}
				else
					std::cerr << "[ERROR] Packet broken" << std::endl;
			}
			else
			{
				std::cerr << "client disconnected" << std::endl;
				this->_sessions.erase(it);
				return;
			}
			delete headerData;
		}
		++it;
	}
}

void		Server::process()
{
	std::map<PacketCode, Action>::const_iterator	it;
	std::map<PacketCode, Action>::const_iterator	ite = this->_actions.end();
	Packet *	pak;
	bool		found = false;

	while (!this->_in.empty())
	{
		found = false;
		pak = new (this->_in.front().second) Packet;
		it = this->_actions.begin();
		while (it != ite)
		{
			if (it->first == pak->header->code)
			{
				(this->*(it->second))(pak);
				found = true;
				delete [] pak->header;
				delete pak;
				break;
			}
			++it;
		}
		if (!found)
			std::cerr << "[RECV] Unknown Packet" << std::endl;
		this->_in.pop_front();
	}
}

Packet *	Server::ActionLogin(Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std::cerr << "[RECV] ActionLogin" << std::endl;
	std::cerr << "\tid: " << data->id << std::endl;
	std::cerr << "\tlogin: " << data->login << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionCreateGame(Packet *)
{
	std:: cerr << "[RECV] ActionCreateGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionAddMap(Packet * pak)
{
	DataMap* data = new (pak->datas) DataMap;
	std::cerr << "[RECV] ActionAddMap" << std::endl;
	std::cerr << "\tmap: " << data->mapName << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionValidGame(Packet *)
{
	std:: cerr << "[RECV] ActionValidGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionJoinGame(Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std::cerr << "[RECV] ActionJoinGame" << std::endl;
	std::cerr << "\tid: " << data->id << std::endl;
	std::cerr << "\tlogin: " << data->login << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionChooseSpacecraft(Packet * pak)
{
	DataSpacecraft* data = new (pak->datas) DataSpacecraft;
	std::cerr << "[RECV] ActionChooseSpacecraft" << std::endl;
	std::cerr << "\tid: " << data->id << std::endl;
	std::cerr << "\tskin: " << data->skin << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionReady(Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std:: cerr << "[RECV] ActionReady" << std::endl;
	std::cerr << "\tid: " << data->id << std::endl;
	std::cerr << "\tlogin: " << data->login << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionNotReady(Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std:: cerr << "[RECV] ActionNotReady" << std::endl;
	std::cerr << "\tid: " << data->id << std::endl;
	std::cerr << "\tlogin: " << data->login << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionStartGame(Packet *)
{
	std:: cerr << "[RECV] ActionStartGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionStopGame(Packet *)
{
	std:: cerr << "[RECV] ActionStopGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionQuitGame(Packet *)
{
	std:: cerr << "[RECV] ActionQuitGame" << std::endl;
	return NULL;
}

