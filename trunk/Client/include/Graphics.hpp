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

#include "NetWork.hpp"

class				Graphics
{
  sf::RenderWindow		_App;
  std::map<int, sf::Image>	_m_sprite;
  int				_height;
  int				_width;
  int				_bpp;
  std::string			_name;

  sf::Image			_Image;
  sf::Sprite			_Player;

public:
  Graphics();
  ~Graphics();
  void			create_windows();
  void			close_windows();
  void			sprite_display(int, int);
  void			sprite_destroy();
  void			load();
  void			sprite_move();
  void			sprite_anim();
  void			draw();
  void			getEvent(float);
  void			loop(NetWork&);
};

#endif			/* __GRAPHICS_HPP__ */
