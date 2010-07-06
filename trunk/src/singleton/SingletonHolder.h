/*!
 * \file	SingletonHolder.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	06/07/2010 18:41:13
 */

#ifndef		SINGLETONHOLDER_H__
# define	SINGLETONHOLDER_H__

# include	"PolicyCreatorNew.h"
# include	"PolicyThreadSingle.h"

# include <iostream>
template <
	class T,
	template <class> class CreationPolicy = PolicyCreatorNew,
	class ThreadPolicy = PolicyThreadSingle
>
class		SingletonHolder
{
	public:
		static T*	getInstance()
		{
			if (!_instance)
			{
				ThreadPolicy::lock();
				_instance = CreationPolicy<T>::create();
				ThreadPolicy::unlock();
			}
			return (_instance);
		}

		static void		destroy()
		{
			if (_instance)
			{
				ThreadPolicy::lock();
				CreationPolicy<T>::destroy(_instance);
				_instance = 0;
				ThreadPolicy::unlock();
			}
		}

	private:
		SingletonHolder() {}
		~SingletonHolder() { destroy(); }

	private:
		static T*	_instance;
};

template <
	class T,
	template <class> class CreationPolicy,
	class ThreadPolicy
>
T*	SingletonHolder<T, CreationPolicy, ThreadPolicy>::_instance = 0;

#endif		// SINGLETONHOLDER_H__
