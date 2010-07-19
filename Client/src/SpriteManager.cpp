#include "SpriteManager.hpp"

SpriteManager::SpriteManager(void)
{
}

SpriteManager::~SpriteManager(void)
{
}
#include <iostream>

void SpriteManager::getFiles(std::string const & path)
{
  std::string realpath;
  realpath = path;

#ifdef _WIN32
  realpath += "*.png";
  USES_CONVERSION;
  WIN32_FIND_DATA ffd;
  HANDLE hFind = INVALID_HANDLE_VALUE;
  hFind = FindFirstFile(realpath.c_str(), &ffd);
  if (hFind != INVALID_HANDLE_VALUE)
  {
    do
    {
      _files.push_back(ffd.cFileName);
    }
    while (FindNextFile(hFind, &ffd) != 0);
  }
  FindClose(hFind);
#else
  DIR *dir = opendir(path.c_str());
  struct dirent *elem = new dirent;
  while ((elem = readdir(dir)) != NULL)
  {
    std::string s(elem->d_name);
    if (s.length() > 6 && s.substr(s.length() - 4) == ".png")
      _files.push_back(s);
  }
#endif
}

#include <iostream>

void SpriteManager::loadObjects(std::string const & path)
{
  this->getFiles(path);
  std::list<std::string>::iterator i = _files.begin();
  std::list<std::string>::iterator end = _files.end();

  for (; i != end ; ++i)
  {
    std::cout << (*i) << std::endl;;
    if (std::string("r-typesheet3.png") == (*i))
      this->loadOne(path + *i, (path + *i).substr(0, (path + *i).length() - 4) + ".sd");
  }
}

bool  SpriteManager::getBoolFromInt(int integer)
{
  if (integer == 0)
    return false;
  return true;
}

void  SpriteManager::getInfoFromFile(std::string const &filename, std::string const line, int *data)
{
  int i = 0;
  std::string cell;
  std::stringstream  lineStream(line);
  while (std::getline(lineStream, cell, ';'))
  {
    std::istringstream is(cell);
    is >> data[i++];
  }
  if (i != 9)
  {
    //TODO throw
    std::cerr << "Bad .sd file" << filename << std::endl;
    exit(1);
  }
}


//int left, top, right, bottom, type, object, anim, oneshot, frame;
void  SpriteManager::loadOne(std::string const & file, std::string const & infofile)
{
  AGameObject *object;
  sf::Sprite *sprite;
  sf::Image *image = new sf::Image();
  (*image).LoadFromFile(file);

  std::ifstream ifs(infofile.c_str());
  int infos[9];
  std::string line;
  int first = -1;
  while(std::getline(ifs,line))
  {
    this->getInfoFromFile(infofile, line, infos);
    if (infos[6] != first)
    {
      if (first == -1)
        first = infos[6];
      else
      {
        _sprite.push_back(*object);
      }
      object = new AGameObject(infos[4],infos[5],this->getBoolFromInt(infos[7]));
      first = infos[6];
    }
    sprite = new sf::Sprite((*image));
    sf::Rect<int> place(infos[0], infos[1], infos[2], infos[3]);
    object->AddSprite(infos[8], sprite, place);
  }
  _sprite.push_back(*object);

  std::cout << "taille du vecteur en sortie " << _sprite.size() << std::endl;
}


AGameObject* SpriteManager::getClone(int type, int id)
{
  int i = 0;
  int end = this->_sprite.size();
  while (i < end)
  {
    if (_sprite[i].getEntityType() == type && _sprite[i].getEntityIdentifier() == id)
    {
      return new AGameObject(this->_sprite[i]);
    }
    ++i;
  }
  return NULL;
}

