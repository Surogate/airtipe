/*!
 * \file	Client.cpp
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 20:43:46
 */

#include	"Client.h"

#ifdef		UNIX
Client::Client(int socket) :

	TCPSession(socket),
	_login("player"),
	_logged(false)
{

}
#endif // UNIX

Client::~Client()
{

}

void	Client::setLogin(std::string const & login)
{
	this->_login = login;
}

void	Client::setLogged(bool logged)
{
	this->_logged = logged;
}

std::string const &		Client::getLogin() const
{
	return this->_login;
}

bool	Client::isLogged() const
{
	return this->_logged;
}

