/*
 * Client.hpp
 *
 *  Created on: Jul 5, 2010
 *      Author: Ayden
 */

#ifndef		__CLIENT_HPP__
# define	__CLIENT_HPP__

#include <string>
#include <SFML/Graphics.hpp>
#include "Graphics.hpp"
#include "EventManager.hpp"
#include "Network.hpp"
#include "Ressources.hpp"

class			Client
{
public:
  Graphics*		_wind;
  EventManager*		_event;
  Network		_network;
  Ressources		_ressources;
  std::string		_login;

public:
  Client();
  ~Client();
  sf::RenderWindow&	getRWindow();
  EventManager&		getEventM();
  Network&		getNetwork();
  Ressources&		getRessources();
  void			setLogin(std::string const &);
  void run();
};

#endif		/* __CLIENT_HPP__ */
