/*!
 * \file	CThreadCondition_Unix.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 15:21:46
 */

#include	"thread/CThreadCondition_Unix.h"

CThreadCondition_Unix::CThreadCondition_Unix()
{
	pthread_cond_init(&this->_cond, NULL);
}

CThreadCondition_Unix::~CThreadCondition_Unix()
{
	pthread_cond_destroy(&this->_cond);
}

void	CThreadCondition_Unix::wait(Mutex& mutex)
{
	pthread_cond_wait(&this->_cond, mutex._mid);
}

void	CThreadCondition_Unix::signal()
{
	pthread_cond_signal(&this->_cond);
}

void	CThreadCondition_Unix::broadcast()
{
	pthread_cond_broadcast(&this->_cond);
}
