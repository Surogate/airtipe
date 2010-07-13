/*
 * Ressources.cpp
 *
 *  Created on: Jul 10, 2010
 *      Author: Ayden
 */

#include "Ressources.hpp"

Ressources::Ressources() : _sDatabase()
{
  this->_sDatabase.loadObjects("../ressources/sprites/");
}

Ressources::~Ressources()
{

}


AGameObject*	Ressources::getUniqueObject(int UID)
{
  std::map<int, AGameObject*>::iterator i = _sprites.begin();
  std::map<int, AGameObject*>::iterator end = _sprites.end();

  for (; i != end ; ++i)
    {
      if ((*i).first == UID)
	{
	  return _sprites[UID];
	}
    }


}

void	       Ressources::addClone(int UID, int type, int id)
{
  AGameObject *object = _sDatabase.getClone(type, id);

  if (object != NULL)
    {
      _sprites[UID] = object;
    }
  else
    {
      //TODO throw ...
    }
}
