/*!
 * \file	PacketManager.h
 * \brief	PacketManager class
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 11:42:51 AM
 */

#ifndef		PACKETMANAGER_H__
#define		PACKETMANAGER_H__

# include	"factory/Factory.hpp"
# include	"singleton/SingletonHolder.h"
# include	"factory/DefaultFactoryError.hpp"
# include	"factory/NoThrowFactoryError.hpp"
# include	"packets/Packet.h"
# include	"packets/DataEmpty.h"
# include	"packets/DataId.h"
# include	"packets/DataSynchro.h"
# include	"packets/DataLogin.h"
# include	"packets/DataMap.h"
# include	"packets/DataSpacecraft.h"
# include	"packets/DataEntity.h"


class		PacketManager
{
	typedef	AData*	(AData::*Creator)();
	typedef	Factory<AData, PacketCode, Creator, NoThrowFactoryError> DataFactory;
	typedef	SingletonHolder<DataFactory > SingletonFactory;
	public:
		PacketManager();
		~PacketManager();
		Packet * CreatePacket(PacketCode);
		Packet * CreatePacket(PacketCode, AData *);
		AData * CreateData(PacketCode);
		AData * interpretData(PacketCode, void * buff);

	private:
		DataFactory *	_dataFactory;
};

#endif		// PACKETMANAGER_H__
