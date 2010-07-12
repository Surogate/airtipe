/*!
 * \file	DataSynchro.h
 * \brief	DataSynchro struct declaration
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 10:53:36 AM
 */

#ifndef		DATASYNCHRO_H__
#define		DATASYNCHRO_H__

# include	"packets/AData.h"
# include	"SkinType.h"
# include	"MovementType.h"

struct		DataSynchro : public AData
{
	DataSynchro() : id(1), x(2), y(3), pv(4), time(5), bulletSkin(Tentacle), movement(Circular), startTime(9) {}
	unsigned int	id;
	unsigned int	x;
	unsigned int	y;
	unsigned int	pv;
	int				time; // A Revoir
	SkinType		bulletSkin;
	MovementType	movement;
	int				startTime; // A Revoir
	AData * Clone() { return new DataSynchro; }
};

#endif		// DATASYNCHRO_H__
