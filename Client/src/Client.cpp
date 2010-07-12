/*
 * Client.cpp
 *
 *  Created on: Jul 5, 2010
 *      Author: Ayden
 */

#include <iostream>

#include "Client.hpp"

Client::Client()
{
  std::cout << "Creation Client" << std::endl;
  _Wind = new Graphics(this);
  _Event = new EventManager(this);
}

Client::~Client()
{
  std::cout << "destruction Client" << std::endl;
}

sf::RenderWindow&	Client::getRWindow()
{
	return this->_Wind->getWindow();
}


EventManager&		Client::getEventM()
{
  return *this->_Event;
}

Network&		Client::getNetwork()
{
  return this->_Net;
}
//
//Ressources&		Client::getRessources()
//{
//  return this->_Ressources;
//}
//
void	Client::run()
{
  this->_Wind->create_windows(false);
  this->_Wind->loop();
}
