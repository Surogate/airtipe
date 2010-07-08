/*!
 * \file	CMutex_Unix.cpp
 * \brief	Implementation of CMutex_Unix class
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	01/07/2010 20:35:18
 */

#include	<iostream>
#include	"thread/CMutex_Unix.h"

CMutex_Unix::CMutex_Unix():
		_mid(new pthread_mutex_t)
{
	this->init();
}

CMutex_Unix::~CMutex_Unix()
{
	this->destroy();
}

bool	CMutex_Unix::init()
{
	int res = pthread_mutex_init(this->_mid, NULL);
	if (res != 0)
	{
		std::cerr << "mutex initialisation failed: " << res << std::endl;
		return (false);
	}
	return (true);
}

void	CMutex_Unix::destroy()
{
	int res = pthread_mutex_destroy(this->_mid);
	if (res != 0)
		std::cerr << "mutex initialisation failed: " << res << std::endl;
}

bool	CMutex_Unix::lock()
{
	int res = pthread_mutex_lock(this->_mid);
	if (res != 0)
	{
		std::cerr << "lock failed: " << res << std::endl;
		return (false);
	}
	return (true);
}

bool	CMutex_Unix::trylock()
{
	int res = pthread_mutex_trylock(this->_mid);
	if (res != 0)
		return (false);
	return (true);
}

bool	CMutex_Unix::unlock()
{
	int res = pthread_mutex_unlock(this->_mid);
	if (res != 0)
	{
		std::cerr << "unlock failed: " << res << std::endl;
		return (false);
	}
	return (true);
}

