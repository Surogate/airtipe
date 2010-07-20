/*!
 * file	PacketCodes.h
 * brief	Packet Codes Enum
 * author	Alexis Lucazeau - lucaze_b@epitech.eu
 * version	0.1
 * date	07/07/2010 08:36:10 PM
 */

#ifndef		PACKETCODES_H__
#define		PACKETCODES_H__

enum		PacketCode
{
	Login,
	CreateGame,
	AddMap,
	ValidGame,
	JoinGame,
	ChooseSpacecraft,
	Ready,
	NotReady,
	StartGame,
	StopGame,
	QuitGame,
	Move,
	Shoot,
	LoginOK,
	CreateGameOK,
	SendGames,
	SendMaps,
	SendMapsEnd,
	AddMapOK,
	ValidGameOK,
	JoinGameOK,
	LeftGame,
	PlayerReady,
	PlayerNotReady,
	PartyStarting,
	SendGrounds,
	SendGroundsEnd,
	LoginAlreadyExists,
	BadLoginFormat,
	LoginKO,
	CreateGameKO,
	UnknownMap,
	ValidGameKO,
	EntitySpawn,
	EntityMove,
	EntityShoot,
	EntityDie,
	EntitySynchro,
	NoCode
};

#endif		// PACKETCODES_H__
