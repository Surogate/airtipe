
#ifdef WIN32
#include "thread/CMutex_Win32.h"

CMutex_Win32::CMutex_Win32()
{
	InitializeCriticalSection(&this->_criticalSection);
}

CMutex_Win32::~CMutex_Win32()
{
	DeleteCriticalSection(&this->_criticalSection);
}

bool	CMutex_Win32::lock()
{
	EnterCriticalSection(&this->_criticalSection);
	return (true);
}

bool	CMutex_Win32::trylock()
{
	BOOL ret = TryEnterCriticalSection(&this->_criticalSection);
	if (ret)
		return (true);
	return (false);
}

bool	CMutex_Win32::unlock()
{
	LeaveCriticalSection(&this->_criticalSection);
	return (true);
}

#endif // !WIN32