/*!
 * \file	PacketHeader.cpp
 * \brief	PacketHeader implementation
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 05:14:15 PM
 */

#include	"packets/PacketHeader.h"

PacketHeader::PacketHeader()
{

}

PacketHeader::PacketHeader(PacketCode code) : code(code), timestamp(0), dataSize(0)
{

}

