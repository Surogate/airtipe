/*!
 * \file	CAbsMutex_Unix.cpp
 * \brief	Implementation of CAbsMutex_Unix class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	01/07/2010 20:35:18
 */

#include	<iostream>
#include	"CAbsMutex_Unix.h"

CAbsMutex_Unix::CAbsMutex_Unix():
		_mid(new pthread_mutex_t)
{

}

CAbsMutex_Unix::~CAbsMutex_Unix()
{

}

bool	CAbsMutex_Unix::init()
{
	int res = pthread_mutex_init(this->_mid, NULL);
	if (res != 0)
	{
		std::cerr << "mutex initialisation failed: " << res << std::endl;
		return (false);
	}
	return (true);
}

void	CAbsMutex_Unix::destroy()
{
	int res = pthread_mutex_destroy(this->_mid);
	if (res != 0)
		std::cerr << "mutex initialisation failed: " << res << std::endl;
}

bool	CAbsMutex_Unix::lock()
{
	int res = pthread_mutex_lock(this->_mid);
	if (res != 0)
	{
		std::cerr << "lock failed: " << res << std::endl;
		return (false);
	}
	return (true);
}

bool	CAbsMutex_Unix::tryLock()
{
	return (false);
}

bool	CAbsMutex_Unix::unlock()
{
	int res = pthread_mutex_unlock(this->_mid);
	if (res != 0)
	{
		std::cerr << "unlock failed: " << res << std::endl;
		return (false);
	}
	return (true);
}

