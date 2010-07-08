/*!
 * \file	EntityFemme.hpp
 * \brief	
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/06/2010 01:01:02 PM
 *
 * more description...
 */

#ifndef		ENTITYFEMME_H__
#define		ENTITYFEMME_H__

# include	<iostream>
# include	"IEntity.h"

class		EntityFemme : public IEntity
{
	public:
	void	printHello()
	{
		std::cout << "Je suis une femme" << std::endl;
	}
	IEntity * Clone()
	{
		return new EntityFemme;
	}
};

#endif		// ENTITYFEMME_H__
