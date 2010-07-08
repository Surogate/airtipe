/*!
 * \file	main.cpp
 * \brief	
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/06/2010 12:56:03 PM
 *
 * more description...
 */

#include	<map>

#include	"factory/DefaultFactoryError.hpp"
#include	"factory/NoThrowFactoryError.hpp"
#include	"factory/Factory.hpp"

#include	"packets/Packet.h"
#include	"packets/AData.h"
#include	"packets/DataEmpty.h"
#include	"packets/DataId.h"
#include	"packets/DataSynchro.h"

void hex_dump(void *data, int size);

int			main()
{
	typedef AData* (AData::*Creator)();
	typedef Factory<AData, PacketCode, Creator, NoThrowFactoryError> EntityFactory;

	EntityFactory entityFactory;

	entityFactory.Register(Login, new DataEmpty, &AData::Clone);
	entityFactory.Register(EntityShoot, new DataId, &AData::Clone);
	entityFactory.Register(EntitySynchro, new DataSynchro, &AData::Clone);

	DataId* myDataId = new (entityFactory.CreateObject(Login)) DataId;
	DataEmpty* myDataEmpty = new (entityFactory.CreateObject(EntityShoot)) DataEmpty;
	DataSynchro* myDataSynchro = new (entityFactory.CreateObject(EntitySynchro)) DataSynchro;

	hex_dump(myDataSynchro, sizeof(*myDataSynchro));

	return(0);
}

