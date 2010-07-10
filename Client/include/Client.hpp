/*
 * Client.hpp
 *
 *  Created on: Jul 5, 2010
 *      Author: Ayden
 */

#ifndef		__CLIENT_HPP__
# define	__CLIENT_HPP__

#include <SFML/Graphics.hpp>

#include "Graphics.hpp"
#include "EventManager.hpp"
#include "Network.hpp"
#include "Ressources.hpp"

class			Client
{
  sf::RenderWindow	_rwindow;

public:

  Graphics		_Wind;
  EventManager		_Event;
  Network		_Net;
  Ressources		_Ressources;

public:
  Client();
  ~Client();
  sf::RenderWindow&	getrwindows();
  EventManager&		getEventM();
  Network&		getNetwork();
  Ressources&		getRessources();
  void run();
};

#endif		/* __CLIENT_HPP__ */
