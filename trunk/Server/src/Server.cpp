/*!
 * \file	Server.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 20:00:43
 */

#include	<sys/socket.h>
#include	<iomanip>
#include	<cstring>
#include	<fcntl.h>
#include	"Server.h"

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
		fcntl(newSock, F_SETFL, O_NONBLOCK);
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
					this->DisplayHeader(header);
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
								this->DisplayError("Packet broken");
						}
						else
						{
							this->DisplayNotice("Client disconnected");
							this->_sessions.erase(it);
							return;
						}
						delete packetData;
					}
				}
				else
					this->DisplayError("Packet broken");
			}
			else
			{
				this->DisplayNotice("Client disconnected");
				this->_sessions.erase(it);
				return;
			}
			delete headerData;
		}
		++it;
	}
}

void		Server::respondToValidClients()
{
	Data	toWrite;
	std::list<std::pair<TCPSession*, void*> >::iterator	it = this->_out.begin();
	while (it != this->_out.end())
	{
		if (FD_ISSET(it->first->getSocket(), &this->_fdw))
		{
			Packet *	packet = new (it->second) Packet;
			toWrite.size = sizeof(PacketHeader);
			toWrite.data = packet->header;
			unsigned int res = it->first->write(toWrite);
			if (res == toWrite.size)
			{
				std::cout << "----- header sent" << std::endl;
				if (packet->header->dataSize != 0)
				{
					toWrite.size = packet->header->dataSize;
					toWrite.data = packet->datas;
					res = it->first->write(toWrite);
					if (res == toWrite.size)
					{
						std::cout << "----- data sent" << std::endl;
						//delete packet; // LEAK HERE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						it = this->_out.erase(it);
						return;
					}
					else
						this->DisplayError("Write failed (or partially failed) ... retrying later");
				}
			}
			else
				this->DisplayError("Write failed (or partially failed) ... retrying later");
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
				Packet* response = (this->*(it->second))(new (this->_in.front().first) Client(this->_in.front().first->getSocket()), pak);
				this->_out.push_back(std::pair<TCPSession*, void*>(this->_in.front().first, response));
				found = true;
				delete [] pak->header;
				delete pak;
				break;
			}
			++it;
		}
		if (!found)
			this->DisplayWarning("Unknown Packet");
		this->_in.pop_front();
	}
}

bool		Server::loginExists(std::string const & login)
{
	std::list<TCPSession*>::const_iterator	it = this->_sessions.begin();
	std::list<TCPSession*>::const_iterator	ite = this->_sessions.end();
	Client *	client;

	while (it != ite)
	{
		client = dynamic_cast<Client *>(*it);
		if (client->isLogged() == true && client->getLogin() == login)
			return true;
		++it;
	}
	return false;
}

Packet *	Server::ActionLogin(Client * client, Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionLogin" << std::endl;
	std::cerr << "\t\tid: " << data->id << std::endl;
	std::cerr << "\t\tlogin: " << data->login << std::endl;
	Packet *		response = NULL;

	if (!this->loginExists(data->login))
	{
		client->setLogin(data->login);
		client->setLogged(true);
		this->DisplayNotice(client->getLogin() + std::string(" now logged"));

		DataLogin * newdata = new (this->_pm.CreateData(LoginOK)) DataLogin;
		memcpy(&newdata->login, &data->login, 15);
		newdata->id = 0;
		response = this->_pm.CreatePacket(LoginOK, newdata);
		response->header->dataSize = sizeof(DataLogin);
	}
	else
	{
		response = this->_pm.CreatePacket(LoginKO);
		response->header->dataSize = sizeof(DataEmpty);
		this->DisplayWarning("Login already exists");
	}
	delete [] data;
	return response;
}

Packet *	Server::ActionCreateGame(Client *, Packet *)
{
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionCreateGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionAddMap(Client *, Packet * pak)
{
	DataMap* data = new (pak->datas) DataMap;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionAddMap" << std::endl;
	std::cerr << "\t\tmap: " << data->mapName << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionValidGame(Client *, Packet *)
{
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionValidGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionJoinGame(Client *, Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionJoinGame" << std::endl;
	std::cerr << "\t\tid: " << data->id << std::endl;
	std::cerr << "\t\tlogin: " << data->login << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionChooseSpacecraft(Client *, Packet * pak)
{
	DataSpacecraft* data = new (pak->datas) DataSpacecraft;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionChooseSpacecraft" << std::endl;
	std::cerr << "\t\tid: " << data->id << std::endl;
	std::cerr << "\t\tskin: " << data->skin << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionReady(Client *, Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionReady" << std::endl;
	std::cerr << "\t\tid: " << data->id << std::endl;
	std::cerr << "\t\tlogin: " << data->login << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionNotReady(Client *, Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionNotReady" << std::endl;
	std::cerr << "\t\tid: " << data->id << std::endl;
	std::cerr << "\t\tlogin: " << data->login << std::endl;
	delete [] data;
	return NULL;
}

Packet *	Server::ActionStartGame(Client *, Packet *)
{
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionStartGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionStopGame(Client *, Packet *)
{
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionStopGame" << std::endl;
	return NULL;
}

Packet *	Server::ActionQuitGame(Client *, Packet *)
{
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionQuitGame" << std::endl;
	return NULL;
}

void		Server::DisplayHeader(PacketHeader * header)
{
	std::cerr << std::setw(10) << std::left << "[RECV]" << "code:" << header->code
		<< " timestamp:" << header->timestamp
		<< " datasize:" << header->dataSize
		<< std::endl;
}

