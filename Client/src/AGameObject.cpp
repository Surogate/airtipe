#include "AGameObject.hpp"

#include <iostream>

AGameObject::AGameObject(int type, int id, bool oneShotAnim) :
_entityType(type), _entityIdentifier(id), _oneShotAnim(oneShotAnim), _UniqueID(0), _posX(50), _posY(50), _currentFrame(0)
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
    this->_posX = obj._posX;
    this->_posY = obj._posY;
    std::cout << "taille de la map constructeur par copie " << this->_animation.size() << std::endl;
  }
  return *this;
}

AGameObject::~AGameObject(void)
{

}

void  AGameObject::AddSprite(int frameNumber, sf::Sprite *sprite, sf::Rect<int> const & place)
{
  std::cout << "Ajout de frame : " << frameNumber << std::endl;
  std::cout << "H:" << place.GetHeight() << " L:" << place.GetWidth() << std::endl;
  (*sprite).SetSubRect(place);
  (*sprite).SetPosition(50,50);
  this->_animation[frameNumber] = (*sprite);
}


void  AGameObject::setUniqueIDentifier(unsigned int UniqueID)
{
  _UniqueID = UniqueID;
}

void  AGameObject::setCurrentFrame(int frameNumber)
{
  _currentFrame = frameNumber;
}

unsigned int  AGameObject::getUniqueIDentifier() const
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

const sf::Sprite & AGameObject::getSprite(int frame)
{
  return this->_animation[frame];
}


void  AGameObject::goNextFrame()
{
  ++_currentFrame;
  if ((this->_currentFrame % (this->_animation.size())) == 0)
    this->_currentFrame = 0;
}


void  AGameObject::goPreviousFrame()
{
  --_currentFrame;
  if (_currentFrame < 0)
    this->_currentFrame = this->_animation.size();
}

sf::Sprite&  AGameObject::draw()
{
  this->_animation[_currentFrame].SetPosition(this->_posX, this->_posY);
  return (this->_animation[_currentFrame]);
}

void  AGameObject::action(int x, int y, int dir, int shoot)
{
  std::cout << dir << std::endl;
}
