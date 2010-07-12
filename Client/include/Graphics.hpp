/*
 * Graphics.hpp
 *
 *  Created on: Jul 3, 2010
 *      Author: Ayden
 */

#ifndef			__GRAPHICS_HPP__
#define			__GRAPHICS_HPP__

#include <SFML/Graphics.hpp>
#include <iostream>

class Client;
class Network;
class EventManager;

class				Graphics
{
  Client			*_client;
  sf::RenderWindow*	_rwindow;
  int				_height;
  int				_width;
  int				_bpp;
  std::string			_name;

public:
  Graphics(Client *);
  ~Graphics();
  void			create_windows(bool fullScreen);
  void			close_windows();
  void			sprite_display(int x, int y);
  void			sprite_destroy();
  void			load();
  void			sprite_move();
  void			sprite_anim();
  void			loop();
  void			draw();
  sf::RenderWindow & getWindow();
};

#endif			/* __GRAPHICS_HPP__ */
