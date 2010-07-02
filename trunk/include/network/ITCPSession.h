/*!
 * \file	ITCPSession.h
 * \brief	Interface over a server-side client session on a TCP server
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	02/07/2010 11:12:56
 */

#ifndef		ITCPSESSION_H__
# define	ITCPSESSION_H__

/*!
 * \brief	The block of data, write or read
 */
typedef void*	Data;

/*!
 * \brief	Interafce over a server-side client session on a TCP server
 */
class		ITCPSession
{
	public:
		/*!
		 * \brief	Write some data to the client owning the session
		 * \param	in: the data to write
		 * \param	size to write (in bytes)
		 * \return	the size wrote (in bytes). -1 if an error occured
		 */
		virtual int		write(Data data, unsigned int size) = 0;

		/*!
		 * \brief	Read some data from the client owning the session
		 * \param	out: the buffer where the read data are wrote
		 * \paran	size to read (in bytes)
		 * \return	the size read (in bytes). -1 if an error occured
		 */
		virtual int		read(Data data, unsigned int size) = 0;

		/*!
		 * \brief	Close the session
		 * \return	true if the sessions is correctly close. else false.
		 */
		virtual bool	close() = 0;
};

#endif		// ITCPSESSION_H__
