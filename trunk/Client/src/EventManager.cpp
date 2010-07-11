///*
// * event.cpp
// *
// *  Created on: Jul 10, 2010
// *      Author: Ayden
// */
//
//#include <iostream>
//
//#include "Client.hpp"
//#include "EventManager.hpp"
//
//EventManager::EventManager(Client * c)
//{
//  this->_client = c;
//}
//
//EventManager::~EventManager()
//{
//  // TODO Auto-generated destructor stub
//}
//
//void			EventManager::touchEvent()
//{
//  sf::Event		Event;
//  while (this->_client->getrwindows().GetEvent(Event))
//  {
//    if ((Event.Type == sf::Event::Closed) ||
//        ((Event.Type == sf::Event::KeyPressed)&& (Event.Key.Code == sf::Key::Escape)))
//    {
//      this->_client->getrwindows().Close();
//    }
//  }
//}
//
//void			EventManager::intputEvent(float timestamp)
//{
//  float ElapsedTime = this->_client->getrwindows().GetFrameTime();
///*
//  if (this->_client->getrwindows().GetInput().IsKeyDown(sf::Key::Left))
//    Sprite.Move( -100 * ElapsedTime, 0);
//  if (this->_client->getrwindows().GetInput().IsKeyDown(sf::Key::Right))
//    Sprite.Move( 100 * ElapsedTime, 0);
//  if (this->_client->getrwindows().GetInput().IsKeyDown(sf::Key::Up))
//    Sprite.Move(0, -100 * ElapsedTime);
//  if (this->_client->getrwindows().GetInput().IsKeyDown(sf::Key::Down))
//    Sprite.Move(0,  100 * ElapsedTime);
//*/
//}
//
//void			EventManager::getEvent(float timestamp)
//{
//  this->touchEvent();
//  this->intputEvent(timestamp);
//}
