#ifndef		_AGAMEOBJECT_H_
# define	_AGAMEOBJECT_H_

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class AGameObject
{
private:
	std::map<int, sf::Sprite>	_animation;
	unsigned int				_UniqueID;
	int							_entityType;
	int							_entityIdentifier;
	int							_currentFrame;
	bool						_oneShotAnim;
	//posix implementation
	int							_posX;
	int							_posY;


public:
	AGameObject(int type, int id, bool oneShotAnim);
	AGameObject(AGameObject const & copy);
	AGameObject & operator=(AGameObject const & obj);
	~AGameObject(void);

	//Getter
	unsigned int getUniqueIDentifier() const;
	int getEntityType() const;
	int getEntityIdentifier() const;

	//Setter
	void	setUniqueIDentifier(unsigned int UniqueID);
	void	setCurrentFrame(int frameNumber);
	
	//Sprite Manipulation
	const	sf::Sprite & getSprite(int frame);
	void	AddSprite(int frameNumber, sf::Sprite *sprite, sf::Rect<int> const & place);
	void	goNextFrame();
	void	goPreviousFrame();
	void	draw(sf::RenderWindow & window);
};

#endif