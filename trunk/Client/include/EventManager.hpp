/*
 * event.h
 *
 *  Created on: Jul 10, 2010
 *      Author: Ayden
 */

#ifndef         __EVENTMANAGER_HPP__
#define         __EVENTMANAGER_HPP__

#include <SFML/Graphics.hpp>

class Client;

class           EventManager
{
  Client        *_client;
  enum dir
  {
    move_r,
    move_dr,
    move_d,
    move_dl,
    move_l,
    move_ul,
    move_u,
    move_ur,
  };
public:
  EventManager(Client *);
  ~EventManager();
  void  touchEvent();
  int  intputEvent(float);
  void  getEvent(float);
};

#endif          /* __EVENT_H__ */
