/*!
 * \file	ATPTask.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 14:40:42
 */

#include	"thread/TPThread.h"
#include	"thread/ATPTask.h"

ATPTask::ATPTask() :
	_thread(0)
{

}

ATPTask::~ATPTask()
{

}

TPThread*	ATPTask::getThread()
{
	return (this->_thread);
}

void		ATPTask::setThread(TPThread* thread)
{
	this->_thread = thread;
}
