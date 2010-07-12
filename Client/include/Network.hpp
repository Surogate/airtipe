/*
 * NetWork.h
 *
 *  Created on: Jul 5, 2010
 *      Author: Ayden
 */

#ifndef		__NETWORK_H__
#define		__NETWORK_H__

#include <SFML/Network.hpp>

class Network
{
private:
	sf::SocketTCP	_socket;

public:
  Network();
  ~Network();
  void getEvent();
  bool	tryConnect(std::string ipaddr, unsigned short port);
};

#endif		/* __NETWORK_H__ */
