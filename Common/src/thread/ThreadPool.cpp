/*!
 * \file	ThreadPool.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	08/07/2010 14:51:14
 */

#include	<iostream>
#include	<algorithm>
#include	"thread/ThreadPool.h"

ThreadPool::ThreadPool(unsigned int maxThread) :
	_maxThread(maxThread)
{
	this->_threads.resize(this->_maxThread);
	for (unsigned int i = 0; i < this->_maxThread; i++)
	{
		this->_threads[i] = new TPThread(this);
		this->_idleThreads.push_back(this->_threads[i]);
		this->_threads[i]->start(true);
	}
}

ThreadPool::~ThreadPool()
{
	unsigned int i = 0;
	syncAll();
	for (i = 0; i < this->_maxThread; i++)
	{
		this->_threads[i]->_syncMutex.lock();
		this->_threads[i]->_end = true;
		this->_threads[i]->setTask(NULL, NULL);
		this->_threads[i]->_workMutex.lock();
		this->_threads[i]->_workCondition.signal();
		this->_threads[i]->_workMutex.unlock();
		this->_threads[i]->_syncMutex.unlock();
	}
	for (i = 0; i < this->_maxThread; i++)
	{
		this->_threads[i]->_deleteMutex.lock();
		delete this->_threads[i];
	}
}

void	ThreadPool::run(ATPTask* task, void* data, bool destroy)
{
	TPThread*	thread = this->getIdle();
	if (thread != NULL)
	{
		thread->_syncMutex.lock();
		thread->setTask(task, data, destroy);
		task->setThread(thread);
		thread->_workMutex.lock();
		thread->_workCondition.signal();
		thread->_workMutex.unlock();
	}
	else
	{
		// stock request !!!!
	}
}

void	ThreadPool::sync(ATPTask* task)
{
	if (task != NULL)
	{
		TPThread*	thread = task->getThread();
		if (thread != NULL)
		{
			thread->_syncMutex.lock();
			thread->setTask(NULL, NULL);
			thread->_syncMutex.unlock();
			task->setThread(NULL);
		}
	}
}

void	ThreadPool::syncAll()
{
	for (unsigned int i = 0; i < this->_maxThread; i++)
	{
		if (this->_threads[i]->_syncMutex.trylock())
			this->_threads[i]->_syncMutex.lock();
		this->_threads[i]->_syncMutex.unlock();
	}
}

TPThread*	ThreadPool::getIdle()
{
	this->_idleListMutex.lock();
	if (!this->_idleThreads.empty())
	{
		TPThread*	thread = this->_idleThreads.front();
		this->_idleThreads.pop_front();
		this->_idleListMutex.unlock();
		return (thread);
	}
	this->_idleListMutex.unlock();
	return (NULL);
}

void		ThreadPool::addIdle(TPThread* thread)
{
	this->_idleListMutex.lock();
	std::list<TPThread*>::iterator it = std::find(
				this->_idleThreads.begin(),
				this->_idleThreads.end(),
				thread
	);
	if (it != this->_idleThreads.end())
		return;

	this->_idleThreads.push_back(thread);
	this->_idleListMutex.unlock();
}

