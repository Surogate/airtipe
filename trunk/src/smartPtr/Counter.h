/*!
 * \file	Counter.h
 * \brief	
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	07/07/2010 10:57:32
 */

#ifndef		COUNTER_H__
# define	COUNTER_H__

template	<class T>
class		SmartPointer;

template	<class T>
class		Counter
{
	friend class SmartPointer<T>;

	private:
		Counter(T* p) : count(0), ref(p) {}
		~Counter()
		{
			if (this->count == 0)
				delete this->ref;
		}

	private:
		unsigned int	create()
		{
			return (++this->count);
		}

		unsigned int	release()
		{
			if (this->count == 0)
				throw new T;
			return (--this->count);
		}

	private:
		unsigned int	count;
		T* const		ref;
};

#endif		// COUNTER_H__
