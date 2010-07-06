/*!
 * \file	PolicySPStorageDefault.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	06/07/2010 23:45:50
 */

#ifndef		POLICYSPSTORAGEDEFAULT_H__
# define	POLICYSPSTORAGEDEFAULT_H__

template	<class T>
class		PolicySPStorageDefault
{
	public:
		PolicySPStorageDefault() : _pointer(0) {}
		PolicySPStorageDefault(T* const & p) : _pointer(p) {}

	public:
		T*	operator->() const { return this->_pointer; }
		T&	operator*() const { return *this->_pointer; }

	protected:
		void	destroy() { delete this->_pointer; }

	private:
		T*	_pointer;
};

#endif		// POLICYSPSTORAGEDEFAULT_H__
