/*!
 * \file	CUDPSession_Unix.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	19/07/2010 16:19:58
 */

#include <iostream>
#include "network/CUDPSession_Unix.h"

CUDPSession_Unix::CUDPSession_Unix(unsigned int bufSize) :
	_bufSize(bufSize),
	_data(NULL)
{
	this->_data = new char[bufSize];
}

CUDPSession_Unix::~CUDPSession_Unix()
{
	if (this->_data != NULL)
		delete [] static_cast<char*>(this->_data);
}

int		CUDPSession_Unix::send(void* data, unsigned int size)
{
	return (0);
}

int		CUDPSession_Unix::recv(unsigned int size)
{
	return (0);
}

void*	CUDPSession_Unix::getData()
{
	return (this->_data);
}

