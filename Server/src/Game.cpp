/*!
 * \file	Game.cpp
 * \brief	Game classimplementation
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/09/2010 05:12:27 PM
 */

#include	"Game.h"

Game::Game(std::string const & ownerLogin) :
	_started(false),
	_owner(ownerLogin)
{

}

Game::~Game()
{

}

void	Game::poll()
{

}

void	Game::PlayerMove(Packet const &)
{

}

void	Game::PlayerFight(Packet const &)
{

}

void	Game::ReadClients()
{

}

void	Game::RespondClients()
{

}

void	Game::CheckCollisions()
{

}

bool	Game::Start()
{
	return (false);
}

bool	Game::Stop()
{
	return (false);
}

void	Game::MoveEntities()
{

}

void	Game::BroadcastMapState()
{

}

void	Game::AddAPlayer(TCPSession *)
{

}

void	Game::DelAPlayer(TCPSession *)
{

}

void	Game::SetAPlayerReady(TCPSession *, bool)
{

}

bool	Game::IsValid()
{
	return (false);
}

bool	Game::IsStarted()
{
	return (false);
}

void	Game::SetValid(bool)
{

}

bool	Game::PlayerChooseSpacecraft(TCPSession *, SkinType)
{
	return (false);
}

void	Game::BroadcastPacket(Packet *)
{

}

std::string const & Game::getOwner() const
{
	return (this->_owner);
}
