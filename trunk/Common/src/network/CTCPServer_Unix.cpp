/*!
 * \file	CTCPServer_Unix.cpp
 * \brief	Implementation of class CTCPServer_Unix
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 09:52:00
 */

#ifndef WIN32
#include	<iostream>
#include	<iomanip>
#include	<cstdlib>
#include	<cstring>
#include	<fcntl.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	"network/CTCPServer_Unix.h"

CTCPServer_Unix::CTCPServer_Unix(short port, unsigned int bufferSize) :
	_port(port),
	_socket(-1),
	_bufferSize(bufferSize),
	_running(false)
{

}

CTCPServer_Unix::~CTCPServer_Unix()
{

}

bool	CTCPServer_Unix::init()
{
	int 				res;
	struct sockaddr_in	saddr;

	memset(&saddr, 0, sizeof(saddr));
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(this->_port);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);

	// socket
	this->_socket = socket(saddr.sin_family, SOCK_STREAM, 0);
	if (this->_socket < 0)
	{
		this->DisplayError("Socket failed");
		return (false);
	}
	// non blocking
	fcntl(this->_socket, F_SETFL, O_NONBLOCK);
	// bind
	res = bind(this->_socket, (sockaddr*)&saddr, sizeof(saddr));
	if (res == -1)
	{
		this->DisplayError("Bind failed");
		::close(this->_socket);
		this->_socket = -1;
		return (false);
	}
	// listen
	res = listen(this->_socket, 10);
	if (res != 0)
	{
		this->DisplayError("Listen failed");
		::close(this->_socket);
		this->_socket = -1;
		return (false);
	}
	return (true);
}

void	CTCPServer_Unix::run()
{
	this->_running = true;
	while (this->_running)
	{
		if (this->accept())
			this->DisplayNotice("New client");
		if (this->poll())
		{
			this->readValidClients();
			this->respondToValidClients();
		}
		this->process();
	}
}

void	CTCPServer_Unix::process()
{
	while (!this->_in.empty())
	{
	//	this->_out.push_back(this->_in.front());
		this->_in.pop_front();
	}
}

void	CTCPServer_Unix::readValidClients()
{
	std::list<TCPSession*>::iterator	it = this->_sessions.begin();
	while (it != this->_sessions.end())
	{
		if (FD_ISSET((*it)->getSocket(), &this->_fdr))
		{
			Data*	data = new Data(this->_bufferSize);
			int res = (*it)->read(*data);
			if (res != -1)
				this->_in.push_back(std::pair<TCPSession*, void*>(*it, data));
			else
			{
				this->DisplayNotice("Client disconnected");
				it = this->_sessions.erase(it);
				return;
			}
		}
		++it;
	}
}

void	CTCPServer_Unix::respondToValidClients()
{
	std::list<std::pair<TCPSession*, void*> >::iterator	it = this->_out.begin();
	while (it != this->_out.end())
	{
		if (FD_ISSET(it->first->getSocket(), &this->_fdw))
		{
			int res = it->first->write(*static_cast<Data*>(it->second));
			if (res == static_cast<int>(static_cast<Data*>(it->second)->size))
			{
				it = this->_out.erase(it);
				return;
			}
			else
				this->DisplayError("Write failed (or partially failed) ... retrying later");
		}
		++it;
	}
}

int		CTCPServer_Unix::resetFdSets()
{
	int	maxSocket = 0;
	FD_ZERO(&this->_fdr);
	FD_ZERO(&this->_fdw);
	std::list<TCPSession*>::iterator	it = this->_sessions.begin();
	std::list<TCPSession*>::iterator	ite = this->_sessions.end();
	while (it != ite)
	{
		if ((*it)->getSocket() > maxSocket)
			maxSocket = (*it)->getSocket();
		FD_SET((*it)->getSocket(), &this->_fdr);
		FD_SET((*it)->getSocket(), &this->_fdw);
		++it;
	}
	return (maxSocket);
}

bool	CTCPServer_Unix::poll()
{
	int maxSocket = this->resetFdSets();
	if (maxSocket != 0)
	{
		int ret = select(maxSocket + 1, &this->_fdr, &this->_fdw, NULL, 0);
		if (ret)
			return (true);
		else if (ret == -1)
			this->DisplayError("Select failed");
	}
	return (false);
}

bool	CTCPServer_Unix::accept()
{
	struct sockaddr	saddr;
	unsigned int	saddrSize = sizeof(saddr);
	int newSock = ::accept(this->_socket, &saddr, &saddrSize);
	if (newSock >= 0)
	{

		fcntl(newSock, F_SETFL, O_NONBLOCK);
		this->_sessions.push_back(new TCPSession(newSock));
		return (true);
	}
	return (false);
}

void	CTCPServer_Unix::close()
{
	if (this->_socket >= 0)
		::close(this->_socket);
}

void	CTCPServer_Unix::DisplayError(std::string const & msg)
{
	std::cerr << std::setw(10) << std::left << "[ERROR]" << msg << std::endl;
}

void	CTCPServer_Unix::DisplayNotice(std::string const & msg)
{
	std::cout << std::setw(10) << std::left << "[NOTICE]" << msg << std::endl;
}

void	CTCPServer_Unix::DisplayWarning(std::string const & msg)
{
	std::cerr << std::setw(10) << std::left << "[WARNING]" << msg << std::endl;
}

#endif
