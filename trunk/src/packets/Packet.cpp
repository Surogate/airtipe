/*!
 * \file	Packet.cpp
 * \brief	Packet class implementation
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 02:23:10 PM
 */

#include "packets/Packet.h"

Packet::Packet()
{

}

Packet::Packet(PacketCode code, AData* datas)
{
	this->header = new PacketHeader(code);
	this->header->dataSize = sizeof(*datas);
	this->datas = datas;
}

Packet::Packet(PacketHeader* header, AData* data)
{
	this->header = header;
	this->datas = data;
}

Packet::Packet(PacketHeader* header)
{
	this->header = header;
}

Packet::~Packet()
{

}

