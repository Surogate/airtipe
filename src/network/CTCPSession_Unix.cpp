/*!
 * \file	CTCPSession_Unix.cpp
 * \brief	Implementation of CTCPSession_Unix class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 11:24:22
 */

#include	<iostream>
#include	<cstdlib>
#include	<cstring>
#include	<fcntl.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<arpa/inet.h>
#include	"network/CTCPSession_Unix.h"
#include	"network/CTCPServer_Unix.h"

CTCPSession_Unix::CTCPSession_Unix(int socket, TCPServer& server, unsigned int bufferSize) :
	_socket(socket),
	_server(server),
	_bufferSize(bufferSize),
	_broken(false)
{
	fcntl(this->_socket, F_SETFL, O_NONBLOCK);
}

CTCPSession_Unix::~CTCPSession_Unix()
{
	this->close();
}

void	CTCPSession_Unix::run()
{
	void*	rdata;
	int		res;

	while (!this->_broken)
	{
		// socket work
		if (this->poll())
		{
			if (this->_canRead)
			{
				//read
				rdata = new char[this->_bufferSize];
				memset(rdata, 0, this->_bufferSize);
				res = this->read(rdata, this->_bufferSize - 1);
				if (res != -1)
					this->_incoming.push_back(rdata);
			}
			if (this->_canWrite && this->mutexOutgoing.tryLock())
			{
				// write
				while (this->outgoing.begin() != this->outgoing.end())
				{
					unsigned int res = this->write(this->outgoing.front(), this->_bufferSize);
					if (res == this->_bufferSize)
						this->outgoing.pop_front();
					else
					{
						std::cerr << "message not tottally sent by " << this->_socket << " ... retrying" << std::endl;
					}
				}
				this->mutexOutgoing.unlock();
			}
		}
		// server communication
		if (this->_incoming.size() > 0 && this->_server.mutexRequests.tryLock())
		{
			while (this->_incoming.begin() != this->_incoming.end())
			{
				this->_server.requests.push_back(std::pair<TCPSession*, Data>(this, this->_incoming.front()));
				this->_incoming.pop_front();
			}
			this->_server.mutexRequests.unlock();
		}
	}
}

bool	CTCPSession_Unix::poll()
{
	fd_set	fdr;
	fd_set	fdw;
	int		ret;

	FD_ZERO(&fdr);
	FD_ZERO(&fdw);
	FD_SET(this->_socket, &fdr);
	FD_SET(this->_socket, &fdw);
	ret = select(this->_socket + 1, &fdw, &fdw, NULL, NULL);
	if (ret == -1)
	{
		std::cerr << "select failed" << std::endl;
		return (false);
	}
	this->_canRead = FD_ISSET(this->_socket, &fdr) ? true : false;
	this->_canWrite = FD_ISSET(this->_socket, &fdw) ? true : false;
	return (true);
}

int		CTCPSession_Unix::write(Data data, unsigned int size)
{
	return (::write(this->_socket, data, size));
}

int		CTCPSession_Unix::read(Data data, unsigned int size)
{
	int res = ::read(this->_socket, data, size);
	if (res != 0)
		return (res);
	std::cerr << "client " << this->_socket << " disconnected" << std::endl;
	this->close();
	this->_broken = true;
	return (-1);
}

bool	CTCPSession_Unix::close()
{
	if (this->_socket >= 0)
	{
		::close(this->_socket);
		this->_socket = -1;
		return (true);
	}
	return (false);
}

int		CTCPSession_Unix::getSocket() const
{
	return (this->_socket);
}

