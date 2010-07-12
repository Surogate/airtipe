/*!
 * \file	DataEntity.h
 * \brief	DataEntity struc
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 01:59:29 PM
 */

#ifndef		DATAENTITY_H__
#define		DATAENTITY_H__

# include	"packets/AData.h"
# include	"EntityType.h"
# include	"SkinType.h"
# include	"MovementType.h"

struct		DataEntity : public AData
{
	unsigned int	id;
	unsigned int	pv;
	unsigned int	x;
	unsigned int	y;
	EntityType		type;
	SkinType		BulletSkin;
	MovementType	movement;
	unsigned int	spawnFrameNum;
	int				startTime; // A Revoir
	AData * Clone() { return new DataEntity; }
};

#endif		// DATAENTITY_H__
