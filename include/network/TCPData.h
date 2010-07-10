/*!
 * \file	TCPData.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 17:31:51
 */

#ifndef		TCPDATA_H__
# define	TCPDATA_H__

# include	<cstring>

class		TCPData
{
	public:
		TCPData() : size(0), data(NULL) {}
		~TCPData() {}
		TCPData(unsigned int const & psize) : size(psize)
		{
			this->data = new char[size];
			memset(this->data, 0, size);
		}

		unsigned int	size;
		void*			data;
};

#endif		// TCPDATA_H__
