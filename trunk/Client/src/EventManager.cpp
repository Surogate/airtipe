/*
 * event.cpp
 *
 *  Created on: Jul 10, 2010
 *      Author: Ayden
 */

#include <iostream>

#include "Client.hpp"
#include "EventManager.hpp"

EventManager::EventManager(Client * c)
{
  this->_client = c;
}

EventManager::~EventManager()
{
  // TODO Auto-generated destructor stub
}

void  EventManager::touchEvent()
{
  sf::Event Event;
  while (this->_client->getRWindow().GetEvent(Event))
  {
    if (Event.Type == sf::Event::Closed)
      this->_client->getRWindow().Close();
    if (Event.Type == sf::Event::KeyPressed)
      switch (Event.Key.Code)
      {
      case sf::Key::Escape:
        this->_client->getRWindow().Close();
        break;
      default:
        break;
      }
  }
}

int  EventManager::intputEvent(float timestamp)
{
  int shoot = 0;
  float ElapsedTime = this->_client->getRWindow().GetFrameTime();
  if (this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Space))
    shoot = 10;
  if (this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Up) &&
      this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Left))
  {
    std::cout << "up and left" << std::endl;
    return shoot + move_ul;
  }
  if (this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Down) &&
      this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Left))
  {
    std::cout << "down and left" << std::endl;
    return shoot + move_dl;
  }
  if (this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Up) &&
      this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Right))
  {
    std::cout << "up and right" << std::endl;
    return shoot + move_ur;
  }
  if (this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Down) &&
      this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Right))
  {
  std::cout << "down and right" << std::endl;
  return shoot + move_dr;
  }

  if (this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Left))
  {
    std::cout << "left" << std::endl;
    return shoot + move_l;
  }
  if (this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Right))
  {
    std::cout << "right" << std::endl;
    return shoot + move_r;
  }
  if (this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Up))
  {
    std::cout << "up" << std::endl;
    return shoot + 7;
  }
  if (this->_client->getRWindow().GetInput().IsKeyDown(sf::Key::Down))
  {
    std::cout << "down" << std::endl;
    return shoot + 8;
  }
}

void  EventManager::getEvent(float timestamp)
{
  this->touchEvent();
  this->_client->getRessources().getUniqueObject(0)->action(0, 0, this->intputEvent(timestamp), 0);
}
