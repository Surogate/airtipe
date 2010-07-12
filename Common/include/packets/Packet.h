/*!
 * \file	Packet.h
 * \brief	Packet Class
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 07:52:32 PM
 */

#ifndef		PACKET_H__
#define		PACKET_H__

# include	"packets/PacketHeader.h"
# include	"packets/AData.h"

/*!
 * \class	Packet
 * \brief	Packet Mother class for UDP/TCP communication with client
 */
class		Packet
{
	public:
		Packet();
		Packet(PacketCode, AData* datas);
		Packet(PacketHeader*, AData*);
		Packet(PacketHeader*);
		~Packet();
		PacketHeader*	header;
		AData*			datas;
};

#endif		// PACKET_H__
