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
  _wind = new Graphics(this);
  _event = new EventManager(this);
}

Client::~Client()
{
  std::cout << "destruction Client" << std::endl;
}

sf::RenderWindow& Client::getRWindow()
{
  return this->_wind->getWindow();
}


EventManager& Client::getEventM()
{
  return *this->_event;
}

Network&  Client::getNetwork()
{
  return this->_network;
}

Ressources&		Client::getRessources()
{
  return this->_ressources;
}

void	Client::run()
{
  this->_wind->create_windows(false);
  this->_ressources.addClone(0,0,0);
  this->_wind->loop();
}


void  Client::setLogin(std::string const & login)
{
  this->_login = login;
}
