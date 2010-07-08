/*!
 * \file	PacketHeader.h
 * \brief	Packet Header Class
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 08:34:09 PM
 */

#ifndef		PACKETHEADER_H__
#define		PACKETHEADER_H__

#include	"packets/PacketCode.h"

class		PacketHeader
{
	public:
		PacketHeader();
		PacketHeader(PacketCode code);
		PacketCode		code;
		int				timestamp; // A Modifier biensur
		unsigned int 	dataSize;
};

#endif		// PACKETHEADER_H__
