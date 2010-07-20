/*!
 * \file	Game.h
 * \brief	Game class declaration
 * \author	Alexis Lucazeau	voidlucaze_b@epitech.eu
 * \version	0.1
 * \date	07/09/2010 04:54:27 PM
 */

#ifndef		GAME_H__
#define		GAME_H__

# include	<map>
# include	"packets/PacketManager.h"
# include	"SkinType.h"
# include	"IEntity.h"

# ifdef		UNIX
#  include	"network/CTCPSession_Unix.h"
# endif

class		Game
{
	public:
		Game(std::string const & ownerLogin);
		~Game();

	public:
		void	poll();
		std::string const & getOwner() const;

	private:
		void	PlayerMove(Packet const & pak);
		void	PlayerFight(Packet const & pak);
		void	ReadClients();
		void	RespondClients();
		bool	Start();
		bool	Stop();
		void	MoveEntities();
		void	CheckCollisions();
		void	BroadcastMapState();
		void	AddAPlayer(TCPSession * sess);
		void	DelAPlayer(TCPSession * sess);
		void	SetAPlayerReady(TCPSession * sess, bool ready);
		bool	IsValid();
		bool	IsStarted();
		void	SetValid(bool valid);
		bool	PlayerChooseSpacecraft(TCPSession * sess, SkinType skin);
		void	BroadcastPacket(Packet * pak);

	private:
		typedef void	(Game::*Action)(Packet * pak);
		PacketManager	_pm;
		bool			_valid;
		bool			_started;
		std::string		_owner;
		std::map<PacketCode, Action>								_actions;
		std::map<TCPSession *, std::pair<unsigned int, IEntity &> >	_players;
};

#endif		// GAME_H__
