/*!
 * \file	DataId.h
 * \brief	DataId struct declaration
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 08:50:12 PM
 */

#ifndef		DATAID_H__
#define		DATAID_H__

# include	"packets/AData.h"

struct		DataId : public AData
{
	unsigned int	id;
	AData * Clone() { return new DataId; }
};

#endif		// DATAID_H__
