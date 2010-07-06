/*!
 * \file	PolicySPDestructionRefCounted.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 00:20:32
 */

#ifndef		POLICYSPLIFETIMEREFCOUNTED_H__
# define	POLICYSPLIFETIMEREFCOUNTED_H__

template	<class T>
class		PolicySPLifetimeRefCounted
{
	public:
		PolicySPLifetimeRefCounted() : _count(new unsigned int(1)) {}

	public:
		T		clone(T const & val)
		{
			*this->_count++;
			return (val);
		}

		bool	Release(T const &)
		{
			*this->_count--;
			if (*this->count == 0)
			{
				delete (this->_count);
				return (true);
			}
			return (false);
		}

	private:
		unsigned int*	_count;
};

#endif		// POLICYSPLIFETIMEREFCOUNTED_H__
