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
					this->DisplayInHeader(header);
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
							{
								delete header;
								this->DisplayError("Packet broken");
							}
						}
						else
						{
							this->DisplayNotice("Client disconnected");
							delete header;
							delete packetData;
							delete headerData;
							delete (*it);
							this->_sessions.erase(it);
							return;
						}
						delete packetData;
					}
					else
						delete header;
				}
				else
					this->DisplayError("Packet broken");
			}
			else
			{
				this->DisplayNotice("Client disconnected");
				delete headerData;
				delete (*it);
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
 				if (packet->header->dataSize != 0)
				{
					toWrite.size = packet->header->dataSize;
					toWrite.data = packet->datas;
					res = it->first->write(toWrite);
 					if (res == toWrite.size)
					{
						this->DisplayOutHeader(packet->header);
						delete packet->header;
						delete packet->datas;
						delete packet;
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
				Packet* response = (this->*(it->second))(dynamic_cast<Client *>(this->_in.front().first), pak);
				this->_out.push_back(std::pair<TCPSession*, void*>(this->_in.front().first, response));
				found = true;
				delete pak->header;
				delete pak->datas;
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
	bool			error = false;

	if (!client->isLogged())
	{
		if (!this->loginExists(data->login))
		{
			client->setLogin(data->login);
			client->setLogged(true);
			this->DisplayNotice(client->getLogin() + " now logged");

			DataLogin * newdata = new DataLogin;
			memcpy(newdata->login, data->login, 16);
			newdata->id = 0;
			response = this->_pm.CreatePacket(LoginOK, newdata);
			response->header->dataSize = sizeof(DataLogin);
			sendGamesToPlayer(newdata->login);
		}
		else
		{
			error = true;
			this->DisplayWarning("Login already exists");
		}
	}
	else
	{
		error = true;
		this->DisplayWarning("Player already logged");
	}
	if (error)
	{
		response = this->_pm.CreatePacket(LoginKO);
		response->header->dataSize = sizeof(DataEmpty);
	}
	return response;
}

void		Server::sendGamesToPlayer(std::string const & login)
{
	std::list<TCPSession*>::const_iterator	it = this->_sessions.begin();
	std::list<TCPSession*>::const_iterator	ite = this->_sessions.end();
	Client *	client;

	while (it != ite)
	{
		client = dynamic_cast<Client *>(*it);
		if (client->isLogged() == true && client->getLogin() == login)
		{
			std::map<std::string, Game*>::const_iterator	itGame = this->_games.begin();
			std::map<std::string, Game*>::const_iterator	itGameEnd = this->_games.end();

			while (itGame != itGameEnd)
			{
				sendGameToPlayer(client, itGame->first);
				++it;
			}
		}
		++it;
	}
}

void		Server::sendGameToPlayer(Client* client, std::string const & gameName)
{
	DataLogin*		data = new DataLogin;
	memcpy(data->login, gameName.c_str(), gameName.size() + 1);
	data->id = 0;

	PacketHeader*	header = new PacketHeader(SendGames);
	header->dataSize = sizeof(DataLogin);

	Packet*			pak = new Packet(header, data);
	this->_out.push_back(std::pair<TCPSession*, void*>(client, pak));
}

Packet *	Server::ActionCreateGame(Client * client, Packet*)
{
	Packet*			response = NULL;
	DataEmpty*		data = new DataEmpty;

	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionCreateGame" << std::endl;

	if (this->_games.find(client->getLogin()) != this->_games.end())
	{
		this->DisplayWarning(client->getLogin() + " get an error when creating a new game");

		PacketHeader*	header = new PacketHeader(CreateGameKO);
		response = new Packet(header, data);
	}
	else
	{
		this->_games[client->getLogin()] = new Game(client->getLogin());
		this->DisplayNotice(client->getLogin() + " creating new game");
		PacketHeader*	header = new PacketHeader(CreateGameOK);
		header->dataSize = sizeof(DataEmpty);
		DataLogin*		data = new DataLogin;
		memcpy(data->login, client->getLogin().c_str(), client->getLogin().size() + 1);
		data->id = 0;
		response = new Packet(header, data);
		broadcastGames(client->getLogin());
	}
	return response;
}

void		Server::broadcastGames(std::string const & gameName)
{
	this->DisplayNotice(std::string("broacasting new game : ") + gameName + " to all players");
	std::list<TCPSession*>::const_iterator	it = this->_sessions.begin();
	std::list<TCPSession*>::const_iterator	ite = this->_sessions.end();
	Client *	client;

	while (it != ite)
	{
		client = dynamic_cast<Client *>(*it);
		if (client->isLogged() == true)
		{
			PacketHeader*	broadHeader = new PacketHeader(SendGames);
			DataLogin*		broadData = new DataLogin;
			memcpy(broadData->login, gameName.c_str(), gameName.size() + 1);
			broadData->id = 0;
			broadHeader->dataSize = sizeof(DataLogin);
			Packet*			broadPacket = new Packet(broadHeader, broadData);

			this->_out.push_back(std::pair<TCPSession*, void*>((*it), broadPacket));
		}
		++it;
	}
}

Packet *	Server::ActionAddMap(Client *, Packet * pak)
{
	DataMap* data = new (pak->datas) DataMap;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionAddMap" << std::endl;
	std::cerr << "\t\tmap: " << data->mapName << std::endl;
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
	return NULL;
}

Packet *	Server::ActionChooseSpacecraft(Client *, Packet * pak)
{
	DataSpacecraft* data = new (pak->datas) DataSpacecraft;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionChooseSpacecraft" << std::endl;
	std::cerr << "\t\tid: " << data->id << std::endl;
	std::cerr << "\t\tskin: " << data->skin << std::endl;
	return NULL;
}

Packet *	Server::ActionReady(Client *, Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionReady" << std::endl;
	std::cerr << "\t\tid: " << data->id << std::endl;
	std::cerr << "\t\tlogin: " << data->login << std::endl;
	return NULL;
}

Packet *	Server::ActionNotReady(Client *, Packet * pak)
{
	DataLogin* data = new (pak->datas) DataLogin;
	std:: cerr << std::setw(10) << std::left << "[ACTION]" << "ActionNotReady" << std::endl;
	std::cerr << "\t\tid: " << data->id << std::endl;
	std::cerr << "\t\tlogin: " << data->login << std::endl;
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

void		Server::DisplayInHeader(PacketHeader * header)
{
	std::cerr << std::setw(10) << std::left << "[RECV]" << "code:" << header->code
		<< " timestamp:" << header->timestamp
		<< " datasize:" << header->dataSize
		<< std::endl;
}

void		Server::DisplayOutHeader(PacketHeader * header)
{
	std::cerr << std::setw(10) << std::left << "[SEND]" << "code:" << header->code
		<< " timestamp:" << header->timestamp
		<< " datasize:" << header->dataSize
		<< std::endl;
}

