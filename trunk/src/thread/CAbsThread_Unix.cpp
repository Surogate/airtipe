#include <iostream>
#include "CAbsThread_Unix.h"

CAbsThread_Unix::CAbsThread_Unix()
{

}

CAbsThread_Unix::~CAbsThread_Unix()
{

}

bool		CAbsThread_Unix::launch(startRoutine start, void* args)
{
	int ret = pthread_create(&this->_tid, NULL, start, args);
	if (ret != 0)
	{
		std::cerr << "Couldn't create thread: " << ret << std::endl;
		return (false);
	}
	return (true);
}

bool		CAbsThread_Unix::join()
{
	int ret = pthread_join(this->_tid, NULL);
	if (ret != 0)
	{
		std::cerr << "join failed: " << ret << std::cerr;
		return (false);
	}
	return (true);
}

