/*!
 * \file	SmartPointer.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 11:13:07
 *
 * more description...
 */

#ifndef		SMARTPOINTER_H__
# define	SMARTPOINTER_H__

# include	"Counter.h"

#include <iostream>
template	<class T>
class		SmartPointer
{
	public:
		SmartPointer() :
			_counter(0) {}

		SmartPointer(T* p)
		{
			this->_counter = new Counter<T>(p);
			this->_counter->create();
		}

		SmartPointer(SmartPointer<T> const & sp)
		{
			this->_counter = sp._counter;
			if (this->_counter)
				this->_counter->create();
		}

		~SmartPointer()
		{
			std::cout << "destroy" << std::endl;
			this->destroy();
		}

	public:
		T*					operator->()
		{
			if (!this->_counter)
				throw new T;
			return (this->_counter->ref);
		}

		T const *			operator->() const
		{
			if (!this->_counter)
				throw new T;
			return (this->_counter->ref);
		}

		T&					operator*()
		{
			if (!this->_counter)
				throw new T;
			return (*this->_counter->ref);
		}

		T					operator*() const
		{
			if (!this->_counter)
				throw new T;
			return (*this->_counter->ref);
		}

		SmartPointer<T>&	operator=(SmartPointer const & sp)
		{
			if (sp._counter)
				sp._counter->create();
			this->destroy();
			this->_counter = sp._counter;
			return (*this);
		}

	private:
		void	destroy()
		{
			if (this->_counter && this->_counter->release() == 0)
				delete this->_counter;
			this->_counter = 0;
		}

	private:
		Counter<T>*			_counter;
};

#endif		// SMARTPOINTER_H__
