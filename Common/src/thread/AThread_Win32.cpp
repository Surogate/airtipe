#include <iostream>
#include "thread/AThread_Win32.h"

extern		"C"
DWORD WINAPI		_run_AThread_Win32(LPVOID obj)
{
	if (obj != NULL)
		static_cast<AThread_Win32*>(obj)->run();
	return NULL;
}

AThread_Win32::AThread_Win32() :
	_running(false)
{

}

AThread_Win32::~AThread_Win32()
{

}

bool	AThread_Win32::start(bool detached)
{
	return (this->create(detached));
}

void	AThread_Win32::stop()
{
	if (this->_running)
		this->cancel();
}

bool	AThread_Win32::create(bool detached)
{
	if (!this->_running)
	{
		LPDWORD	lpTid = NULL;
		this->_tid = CreateThread(NULL, 0, _run_AThread_Win32, this, 0, lpTid);
		if (this->_tid != NULL)
			return (true);
	}
	return (false);
}

void	AThread_Win32::join()
{
	DWORD ret = WaitForSingleObject(this->_tid, INFINITE);
	if (ret != WAIT_OBJECT_0)
		std::cerr << "join failed" << std::endl;
}

void	AThread_Win32::cancel()
{
	if (this->_running)
	{
		DWORD ret = TerminateThread(this->_tid, 0);
		if (ret == 0)
		{
			std::cerr << "Canceling thread failed" << std::endl;
			BOOL ret = CloseHandle(this->_tid);
			if (ret == 0)
				std::cerr << "Closing thread handle failed" << std::cerr;
		}
	}
}