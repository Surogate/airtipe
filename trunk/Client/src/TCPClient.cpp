/*!
 * \file	TCPClient.cpp
 * \brief	SFML TCPClient wrapper class
 * \author	Aurelien Lebrun - lebrun_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 22:27:15
 *
 */

#include	<SFML/Network.hpp>
#include	<iostream>

#include	"TCPClient.hpp"

TCPClient::TCPClient() 
{
}

TCPClient::~TCPClient()
{

}

void					TCPClient::connect(std::string address, unsigned short port)
{ 
	this->_port = port;
	this->_serverAddress = address;
	this->_client = new sf::SocketTCP;

	if (!this->_serverAddress.IsValid())
		std::cout << "[ERROR] Non-valid address" << std::endl;

	if (this->_client->Connect(this->_port, this->_serverAddress) != sf::Socket::Done)
	{
		this->_fail = true;
		std::cout << "[ERROR] Connection to server failed" << std::endl;
		return ;
	}
	this->_fail = false;
	std::cout << "[INFO] Connected to server:" << this->_serverAddress << std::endl;
}

std::string				TCPClient::receive()
{
	char				buf[512];
	std::string* 		rec = new std::string();

	if (this->_client->Receive(buf, sizeof(buf), this->_received) != sf::Socket::Done)
	{
		std::cout << "[ERROR] Receive failed :/" << std::endl;
		return (*rec);
	}
	rec = new std::string(buf);
	std::cout << "[INFO] Message received: " << buf << std::endl;

	return (*rec);
}

void					TCPClient::send(void * buf, unsigned int bufSize)
{
	if (this->_client->Send(static_cast<const char*>(buf), bufSize) != sf::Socket::Done)
	{
		std::cout << "[ERROR] Send failed :/" << std::endl;
	}
}

bool					TCPClient::failed()
{
	return (this->_fail); 
}
