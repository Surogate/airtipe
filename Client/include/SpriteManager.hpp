#ifndef		_SPRITEMANAGER_H_
# define		_SPRITEMANAGER_H_

# include "AGameObject.hpp"
# include <map>
# include <list>
# include <string>
# include <fstream>
# include <sstream>
# include <vector>

# ifdef _WIN32
# include <io.h>
#  include <atlbase.h>
#  include <windows.h>
#else
#  include <sys/types.h>
#  include <dirent.h>
# endif

class SpriteManager
{
private:
  std::list<std::string>		_files;
  std::vector<AGameObject>	_sprite;

  void getFiles(std::string const & path);
  bool	getBoolFromInt(int integer);
  void	getInfoFromFile(std::string const &filename, std::string const line, int *data);

public:
  SpriteManager(void);
  ~SpriteManager(void);
  void loadObjects(std::string const & path);
  void loadOne(std::string const & file, std::string const & infofile);
  AGameObject* getClone(int type, int id);
};

#endif
