/*!
 * \file	EntityHomme.hpp
 * \brief	
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/06/2010 01:00:44 PM
 *
 * more description...
 */

#ifndef		ENTITYHOMME_H__
#define		ENTITYHOMME_H__

# include	<iostream>
# include	"IEntity.h"

class		EntityHomme : public IEntity
{
	public:
	void	printHello()
	{
		std::cout << "Je suis un homme" << std::endl;
	}
	IEntity * Clone()
	{
		return new EntityHomme;
	}
};

#endif		// ENTITYHOMME_H__
