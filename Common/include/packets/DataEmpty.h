/*!
 * \file	DataEmpty.h
 * \brief	DataEmpty struct declaration
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 08:47:20 PM
 */

#ifndef		DATAEMPTY_H__
#define		DATAEMPTY_H__

# include	"packets/AData.h"

class		DataEmpty : public AData
{
	public:
		AData * Clone() { return new DataEmpty; }
		virtual ~DataEmpty() {}
};

#endif		// DATAEMPTY_H__
