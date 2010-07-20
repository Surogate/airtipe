/*!
 * \file	PacketManager.cpp
 * \brief	Packet manager implementation
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 11:49:19 AM
 */

#include	"packets/PacketManager.h"

PacketManager::PacketManager()
{
	this->_dataFactory = SingletonFactory::getInstance();

	this->_dataFactory->Register(Login, new DataLogin, &AData::Clone);
	this->_dataFactory->Register(CreateGame, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(AddMap, new DataMap, &AData::Clone);
	this->_dataFactory->Register(ValidGame, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(JoinGame, new DataLogin, &AData::Clone);
	this->_dataFactory->Register(Ready, new DataLogin, &AData::Clone);
	this->_dataFactory->Register(NotReady, new DataLogin, &AData::Clone);
	this->_dataFactory->Register(StartGame, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(StopGame, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(QuitGame, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(Move, new DataSynchro, &AData::Clone);
	this->_dataFactory->Register(Shoot, new DataId, &AData::Clone);
	this->_dataFactory->Register(LoginOK, new DataLogin, &AData::Clone);
	this->_dataFactory->Register(CreateGameOK, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(SendGames, new DataLogin, &AData::Clone);
	this->_dataFactory->Register(SendMaps, new DataMap, &AData::Clone);
	this->_dataFactory->Register(SendMapsEnd, new DataMap, &AData::Clone);
	this->_dataFactory->Register(AddMapOK, new DataMap, &AData::Clone);
	this->_dataFactory->Register(ValidGameOK, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(JoinGameOK, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(LeftGame, new DataLogin, &AData::Clone);
	this->_dataFactory->Register(ChooseSpacecraft, new DataSpacecraft, &AData::Clone);
	this->_dataFactory->Register(PlayerReady, new DataLogin, &AData::Clone);
	this->_dataFactory->Register(PlayerNotReady, new DataLogin, &AData::Clone);
	this->_dataFactory->Register(SendGrounds, new DataEntity, &AData::Clone);
 	this->_dataFactory->Register(SendGroundsEnd, new DataEntity, &AData::Clone);
	this->_dataFactory->Register(LoginAlreadyExists, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(BadLoginFormat, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(LoginKO, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(CreateGameKO, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(UnknownMap, new DataMap, &AData::Clone);
	this->_dataFactory->Register(ValidGameKO, new DataEmpty, &AData::Clone);
	this->_dataFactory->Register(EntitySpawn, new DataEntity, &AData::Clone);
	this->_dataFactory->Register(EntityMove, new DataSynchro, &AData::Clone);
	this->_dataFactory->Register(EntitySynchro, new DataSynchro, &AData::Clone);
	this->_dataFactory->Register(EntityShoot, new DataId, &AData::Clone);
	this->_dataFactory->Register(EntityDie, new DataId, &AData::Clone);
}

PacketManager::~PacketManager()
{

}

Packet * PacketManager::CreatePacket(PacketCode code)
{
	return (new Packet(code, this->_dataFactory->CreateObject(code)));
}


Packet * PacketManager::CreatePacket(PacketCode code, AData * data)
{
	return (new Packet(code, data));
}

AData * PacketManager::CreateData(PacketCode code)
{
	return (this->_dataFactory->CreateObject(code));
}

AData * PacketManager::interpretData(PacketCode, void * buff)
{
	return new (buff) AData;
}

