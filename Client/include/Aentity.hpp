/*
 * Ientity.hpp
 *
 *  Created on: Jul 2, 2010
 *      Author: Ayden
 */

#ifndef		IENTITY_HPP_
#define		IENTITY_HPP_

class		Aentity
{
  float		_posx;
  float		_posy;

public:
  enum dir
  {
    up,
    down,
    left,
    right
  };
  virtual ~Aentity();
  virtual void	move_to(float, float);
  virtual void	move_to(dir);
  virtual void	appear(float, float);
  virtual void	destroy();
  virtual void	fire() = 0;

};

#endif		/* IENTITY_HPP_ */
