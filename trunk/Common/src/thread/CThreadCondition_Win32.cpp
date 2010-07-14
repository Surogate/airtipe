#include <iostream>
#include "thread/CThreadCondition_Win32.h"

CThreadCondition_Win32::CThreadCondition_Win32()
{
	InitializeConditionVariable(&this->_condition);
}

CThreadCondition_Win32::~CThreadCondition_Win32()
{

}

void	CThreadCondition_Win32::wait(Mutex& mutex)
{
	BOOL ret = SleepConditionVariableCS(&this->_condition, &mutex._criticalSection, INFINITE);
	if (ret == 0)
		std::cerr << "ThreadCondition wait failed" << std::endl;
}

void	CThreadCondition_Win32::signal()
{
	WakeConditionVariable(&this->_condition);
}

void	CThreadCondition_Win32::broadcast()
{
	WakeAllConditionVariable(&this->_condition);
}