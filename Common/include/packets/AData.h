/*!
 * \file	AData.h
 * \brief	Abstract data struct
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 10:35:21 AM
 */

#ifndef		ADATA_H__
#define		ADATA_H__
#include <iostream>
class		AData
{
	public:
		virtual AData * Clone() { return new AData; }
		virtual ~AData() {}
};

#endif		// ADATA_H__

