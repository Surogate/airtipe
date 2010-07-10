/*
 * event.h
 *
 *  Created on: Jul 10, 2010
 *      Author: Ayden
 */

#ifndef		__EVENTMANAGER_HPP__
#define		__EVENTMANAGER_HPP__

#include <SFML/Graphics.hpp>

class Client;

class			EventManager
{
  Client		*_client;

public:
  EventManager(Client *);
  ~EventManager();
  void			touchEvent();
  void			intputEvent(float);
  void			getEvent(float);
};

#endif		/* __EVENT_H__ */
