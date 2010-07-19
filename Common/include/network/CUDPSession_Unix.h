/*!
 * \file	CUDPSession_Unix.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	19/07/2010 16:16:26
 */

#ifndef		CUDPSESSION__UNIX_H__
# define	CUDPSESSION__UNIX_H__

# include	"network/IUDPSession.h"

class		CUDPSession_Unix : public IUDPSession
{
	public:
		CUDPSession_Unix(unsigned int bufSize = 16);
		virtual ~CUDPSession_Unix();

	public:
		int		send(void* data, unsigned int size);
		int		recv(unsigned int size);

	public:
		void*	getData();

	private:
		unsigned int	_bufSize;
		void*			_data;
};

typedef CUDPSession_Unix	UDPSession;

#endif		// CUDPSESSION_H__

