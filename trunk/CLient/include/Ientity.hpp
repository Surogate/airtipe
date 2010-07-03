/*
 * Ientity.hpp
 *
 *  Created on: Jul 2, 2010
 *      Author: Ayden
 */

#ifndef		IENTITY_HPP_
#define		IENTITY_HPP_

class		Ientity
{
  float		_posx;
  float		_posy;
public:
  virtual ~Ientity() {}
  virtual void	move_to(float, float);
  virtual void	move_to(dir);
  virtual void	appear(float, float);
  virtual void	destroy();
  virtual void	fire() = 0;
protected:
  enum		dir
  {
    up,
    down,
    left,
    right
  }
};

#endif		/* IENTITY_HPP_ */
