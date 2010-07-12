/*
 * NetWork.cpp
 *
 *  Created on: Jul 5, 2010
 *      Author: Ayden
 */

#include <Network.hpp>
#include <iostream>

Network::Network()
{
  std::cout << "Creation NetWork" << std::endl;
}

Network::~Network()
{
  std::cout << "Destroy NetWork" << std::endl;
}

bool	Network::tryConnect(std::string ipaddr, unsigned short port)
{
	std::cout << port << std::endl;
	std::cout << ipaddr << std::endl;
	if (sf::Socket::Done != _socket.Connect(port, ipaddr, 2.f))
		return false;
	return true;
}


void	Network::getEvent()
{
  //std::cout << "network" << std::endl;
}
