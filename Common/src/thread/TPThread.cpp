/*!
 * \file	TPThread.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 14:42:04
 */

#include	<iostream>
#include	"thread/ThreadPool.h"
#include	"thread/TPThread.h"

TPThread::TPThread(ThreadPool* threadPool) :
	_threadPool(threadPool)
{

}

TPThread::~TPThread()
{

}

void	TPThread::run()
{
	// Locking deletion
	this->_deleteMutex.lock();
	while (!this->_end)
	{
		// Waiting for a new task
		this->_workMutex.lock();
		while (this->_task == NULL && ! this->_end)
			this->_workCondition.wait(this->_workMutex);
		this->_workMutex.unlock();

		if (this->_task)
		{
			// running
			this->_task->run(this->_data);
			// reseting
			this->_task->setThread(NULL);
			if (this->_destroy)
				delete this->_task;
			this->setTask(NULL, NULL);
			this->_syncMutex.unlock();
		}
		this->_threadPool->addIdle(this);
	}
	this->_deleteMutex.unlock();
}

void	TPThread::setTask(ATPTask* task, void* data, bool destroy)
{
	this->_taskMutex.lock();
	this->_task = task;
	this->_data = data;
	this->_destroy = destroy;
	this->_taskMutex.unlock();
}

