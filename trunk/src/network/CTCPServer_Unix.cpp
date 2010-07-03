/*!
 * \file	CTCPServer_Unix.cpp
 * \brief	Implementation of class CTCPServer_Unix
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 09:52:00
 */

#include	<iostream>
#include	<cstdlib>
#include	<cstring>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	"network/CTCPServer_Unix.h"

static void*	runClient(void* args)
{
	TCPSession* session = NULL;
	if (args != NULL)
	{
		session = static_cast<TCPSession*>(args);
		session->run();
	}
	return (NULL);
}

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
		std::cerr << "socket failed" << std::endl;
		return (false);
	}
	fcntl(this->_socket, F_SETFL, O_NONBLOCK);
	// bind
	res = bind(this->_socket, (sockaddr*)&saddr, sizeof(saddr));
	if (res == -1)
	{
		std::cerr << "bind failed" << std::endl;
		::close(this->_socket);
		this->_socket = -1;
		return (false);
	}
	// listen
	res = listen(this->_socket, 10);
	if (res != 0)
	{
		std::cerr << "listen failed" << std::endl;
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
			std::cout << "new client" << std::endl;
		this->processData();
	}
}

bool	CTCPServer_Unix::accept()
{
	struct sockaddr	saddr;
	unsigned int	saddrSize = sizeof(saddr);
	int newSock = ::accept(this->_socket, &saddr, &saddrSize);
	if (newSock >= 0)
	{
		TCPSession*		session = new TCPSession(newSock, *this, this->_bufferSize);
		AbsThread*		th = new AbsThread;
		this->_sessions.insert(std::pair<TCPSession*, AbsThread*>(session, th));
		th->launch(&runClient, session);
		return (true);
	}
	return (false);
}

void	CTCPServer_Unix::processData()
{
	if (this->requests.size() > 0 && this->mutexRequests.tryLock())
	{
		while (!this->requests.empty())
		{
			TCPSession*	session = this->requests.begin()->first;
			if (session->mutexOutgoing.tryLock())
			{
				void* response = new char[this->_bufferSize];
				memcpy(response, this->requests.begin()->second, this->_bufferSize);
				session->outgoing.push_back(response);
				this->requests.erase(this->requests.begin());
				session->mutexOutgoing.unlock();
			}
		}
		this->mutexRequests.unlock();
	}
}

void	CTCPServer_Unix::close()
{
	if (this->_socket >= 0)
		::close(this->_socket);
}

