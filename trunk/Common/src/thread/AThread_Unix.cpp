/*!
 * \file	AThread_Unix.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 13:14:44
 */

#include	<iostream>
#include	"thread/AThread_Unix.h"

extern		"C"
void*		_run_AThread_Unix(void* obj)
{
	if (obj != NULL)
		static_cast<AThread_Unix*>(obj)->run();
	return NULL;
}

AThread_Unix::AThread_Unix() :
	_running(false)
{

}

AThread_Unix::~AThread_Unix()
{

}

bool	AThread_Unix::start(bool detached)
{
	return (this->create(detached));
}

void	AThread_Unix::stop()
{
	if (this->_running)
		this->cancel();
}

bool	AThread_Unix::create(bool detached)
{
	if (!this->_running)
	{
		int ret = pthread_attr_init(&this->_tattr);
		if (ret != 0)
		{
			std::cerr << "thread attribute initialisation failed" << std::endl;
			return (false);
		}
		if (detached)
		{
			ret = pthread_attr_setdetachstate(&this->_tattr, PTHREAD_CREATE_DETACHED);
			if (ret != 0)
			{
				std::cerr << "setting detached attribute on thread failed" << std::endl;
				return (false);
			}
		}
		ret = pthread_create(&this->_tid, &this->_tattr, _run_AThread_Unix, this);
		if (ret != 0)
			std::cerr << "creating thread failed" << std::endl;
		else
		{
			this->_running = true;
			return (true);
		}
	}
	return (false);
}

void	AThread_Unix::join()
{
	if (this->_running)
	{
		int ret = pthread_join(this->_tid, NULL);
		if (ret != 0)
			std::cerr << "joining thread failed" << std::endl;
	}
	else
		std::cerr << "thread is not running" << std::endl;
}

void	AThread_Unix::cancel()
{
	if (this->_running)
	{
		int ret = pthread_cancel(this->_tid);
		if (ret != 0)
			std::cerr << "thread cancelation failed" << std::endl;
		else
			this->_running = false;
	}
	else
		std::cerr << "thread is not running" << std::endl;
}

