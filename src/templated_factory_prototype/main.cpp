/*!
 * \file	main.cpp
 * \brief	
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/06/2010 12:56:03 PM
 *
 * more description...
 */

#include	"DefaultFactoryError.hpp"
#include	"NoThrowFactoryError.hpp"
#include	"Factory.hpp"

#include	"EntityFemme.hpp"
#include	"EntityHomme.hpp"

enum EntityType {
	HOMME,
	FEMME,
	NIMP
};

int			main()
{
	typedef IEntity* (IEntity::*Creator)();
	typedef Factory<IEntity, EntityType, Creator, NoThrowFactoryError> EntityFactory;
	//typedef Factory<IEntity, EntityType, Creator, DefaultFactoryError> EntityFactory;
	EntityFactory entityFactory;

	entityFactory.Register(HOMME, new EntityHomme, &IEntity::Clone);
	entityFactory.Register(FEMME, new EntityFemme, &IEntity::Clone);

	IEntity* myEntity = entityFactory.CreateObject(HOMME);
	IEntity* mySecondEntity = entityFactory.CreateObject(FEMME);
	myEntity->printHello();
	mySecondEntity->printHello();

	IEntity* nimp = entityFactory.CreateObject(NIMP);
	nimp->printHello();

/* 	try
	{
		IEntity* nimp = entityFactory.CreateObject(NIMP);
		nimp->printHello();
	}
	catch (EntityFactory::Exception e)
	{
		std::cout << e.what() << " ObjectType:" << e.GetId() << std::endl;
	}
 */
	return(0);
}

