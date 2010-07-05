/*
 * NetWork.cpp
 *
 *  Created on: Jul 5, 2010
 *      Author: Ayden
 */

#include <NetWork.hpp>
#include <iostream>

NetWork::NetWork()
{
  std::cout << "Creation NetWork" << std::endl;
}

NetWork::~NetWork()
{
  std::cout << "Destroy NetWork" << std::endl;
}

void	NetWork::getEvent()
{
  std::cout << "network" << std::endl;
}
