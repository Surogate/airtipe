/*
 * Client.cpp
 *
 *  Created on: Jul 5, 2010
 *      Author: Ayden
 */

#include <iostream>

#include "Client.hpp"

Client::Client() : _Wind(this), _Event(this)
{
  std::cout << "Creation Client" << std::endl;
}

Client::~Client()
{
  std::cout << "destruction Client" << std::endl;
}

sf::RenderWindow&	Client::getRWindow()
{
	return this->_Wind.getWindow();
}


EventManager&		Client::getEventM()
{
  return this->_Event;
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
//void	Client::run()
//{
//  //this->_Wind.create_windows();
//  //this->_Wind.loop();
//
//}
