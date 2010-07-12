/*!
 * \file	Object.h
 * \brief	
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/06/2010 12:56:46 PM
 *
 * more description...
 */

#ifndef				IENTITY_H__
#define				IENTITY_H__

# include 			<iostream>

class				IEntity
{
	public:
	virtual void	printHello()
	{
		std::cout << "Je suis rien du tout" << std::endl;
	}

	virtual IEntity * Clone()
	{
		return new IEntity;
	}
};

#endif				// IENTITY_H__
