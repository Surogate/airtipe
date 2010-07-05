/*
 * Client.cpp
 *
 *  Created on: Jul 5, 2010
 *      Author: Ayden
 */

#include <iostream>

#include "Client.hpp"
#include "Graphics.hpp"

Client::Client()
{
  std::cout << "Creation Client" << std::endl;
}

Client::~Client()
{
  std::cout << "destruction Client" << std::endl;
}

void	Client::run()
{
  this->Wind.create_windows();
  this->Wind.load();
  this->Wind.loop(this->Net);
}
