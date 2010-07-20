/*!
 * \file	DataSpacecraft.h
 * \brief	DataSpacecraft struct
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 01:50:52 PM
 */

#ifndef		DATASPACECRAFT_H__
#define		DATASPACECRAFT_H__

# include	"packets/AData.h"
# include	"SkinType.h"

class		DataSpacecraft : public AData
{
	public:
		unsigned int	id;
		SkinType		skin;
		AData *			Clone() { return new DataSpacecraft; }
		virtual ~DataSpacecraft() {}
};

#endif		// DATASPACECRAFT_H__
