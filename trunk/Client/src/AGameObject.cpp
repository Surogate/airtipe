#include "AGameObject.h"

#include <iostream>

AGameObject::AGameObject(int type, int id, bool oneShotAnim) :
_entityType(type), _entityIdentifier(id), _oneShotAnim(oneShotAnim), _UniqueID(0)
{
  std::cout << "type : " << type << " id : " << id << std::endl;
}

AGameObject::AGameObject(AGameObject const & copy)
{
	*this = copy;
}

AGameObject & AGameObject::operator=(AGameObject const & obj)
{
	if (this != &obj)
	{
		this->_animation = obj._animation;
		this->_UniqueID = obj._UniqueID;
		this->_entityType = obj._entityType;
		this->_entityIdentifier = obj._entityIdentifier;
		this->_currentFrame = obj._currentFrame;
		this->_oneShotAnim = obj._oneShotAnim;
		std::cout << "taille de la map constructeur par copie " << this->_animation.size() << std::endl;
	}
	return *this;
}



AGameObject::~AGameObject(void)
{

}

#include <iostream>

void	AGameObject::AddSprite(int frameNumber, sf::Sprite *sprite, sf::Rect<int> const & place)
{
  std::cout << "Ajout de frame : " << frameNumber << std::endl;
  std::cout << "H:" << place.GetHeight() << " L:" << place.GetWidth() << std::endl;
  (*sprite).SetSubRect(place);
  (*sprite).SetPosition(50,50);
  this->_animation[frameNumber] = (*sprite);
}

void	AGameObject::setUniqueIDentifier(unsigned int UniqueID)
{
  _UniqueID = UniqueID;
}

void	AGameObject::setCurrentFrame(int frameNumber)
{
  _currentFrame = frameNumber;
}

unsigned int	AGameObject::getUniqueIDentifier() const
{
  return _UniqueID;
}

int AGameObject::getEntityType() const
{
  return _entityType;
}

int AGameObject::getEntityIdentifier() const
{
  return _entityIdentifier;
}

int		AGameObject::getNextFrame()
{
  return ++_currentFrame;
}
int		AGameObject::getPrevFrame()
{
  return --_currentFrame;
}

const sf::Sprite & AGameObject::getSprite(int frame)
{
  return this->_animation[frame];
}
