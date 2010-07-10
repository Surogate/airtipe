/*
 * Ressources.h
 *
 *  Created on: Jul 10, 2010
 *      Author: Ayden
 */

#ifndef		__RESSOURCES_HPP__
#define		__RESSOURCES_HPP__

#include <iostream>
#include <SFML/Graphics.hpp>

class				Ressources
{
  std::map<int, sf::Image>	_lbrary;
  sf::Image			texturetest;
  sf::Sprite			playertest;

public:
  Ressources();
  ~Ressources();
};

#endif		/* __RESSOURCES_H__ */
