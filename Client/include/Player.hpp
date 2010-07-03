/*
 * player.hpp
 *
 *  Created on: Jul 2, 2010
 *      Author: Ayden
 */

#ifndef		PLAYER_HPP_
#define		PLAYER_HPP_

#include "Aentity.hpp"

class		Player: public Aentity
{
  Player(Player const &){}
  Player&	operator=(Player const &);
public:
  Player();
  ~Player();
  void	fire();
};

#endif		/* PLAYER_HPP_ */
