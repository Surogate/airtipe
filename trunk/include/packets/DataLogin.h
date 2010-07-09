/*!
 * \file	DataLogin.h
 * \brief	DataLogin Class
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/08/2010 01:09:16 PM
 */

#ifndef		DATALOGIN_H__
#define		DATALOGIN_H__

# include	"packets/AData.h"

struct		DataLogin : public AData
{
	virtual ~DataLogin() { std::cout << "destroy datalogin" << std::endl; }
	unsigned int	id;
	char			login[15];
	AData *			Clone() { return new DataLogin; }

};

#endif		// DATALOGIN_H__
