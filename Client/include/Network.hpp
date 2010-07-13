/*
 * NetWork.h
 *
 *  Created on: Jul 5, 2010
 *      Author: Ayden
 */

#ifndef		__NETWORK_H__
#define		__NETWORK_H__

#include <SFML/Network.hpp>
#include "PacketCode.h"
#include "PacketManager.h"

class Network
{
private:
	sf::SocketTCP	_socket;
  PacketManager		_pacManager;
public:
  Network();
  ~Network();
  void getEvent();
  bool	tryConnect(std::string ipaddr, unsigned short port);
  bool	isConnected() const;
  void	sendInitPacket(std::string const &);
};

#endif		/* __NETWORK_H__ */
