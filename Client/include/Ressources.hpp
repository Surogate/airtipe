/*
 * Ressources.h
 *
 *  Created on: Jul 10, 2010
 *      Author: Ayden
 */

#ifndef		__RESSOURCES_HPP__
#define		__RESSOURCES_HPP__

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "AGameObject.hpp"
#include "SpriteManager.hpp"


class				Ressources
{
  std::map<int, AGameObject*>	_sprites;
  SpriteManager			_sDatabase;

public:
  Ressources();
  ~Ressources();
  void addClone(int UID, int type, int id);
  AGameObject*	getUniqueObject(int UID);
};

#endif		/* __RESSOURCES_H__ */
