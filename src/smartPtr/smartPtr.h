/*!
 * \file	smartPtr.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	06/07/2010 23:40:54
 */

#ifndef		SMARTPTR_H__
# define	SMARTPTR_H__

# include	"PolicySPStorageDefault.h"
# include	"PolicySPDestructionRefCounted.h"

template <
	typename T,
	template <class> class LifetimePolicy = PolicySPDestructionRefCounted,
	template <class> class StoragePolicy = PolicySPStorageDefault
>
class		SmartPtr : public StoragePolicy<T>
{
	public:
		SmartPtr() : StoragePolicy<T>() {}
		SmartPtr(T* const & p) : StoragePolicy<T>(p) {}
};

#endif		// SMARTPTR_H__
