/*!
 * \file	PolicyCreatorNew.h
 * \brief	Template policy class to create objects.
 * \author	Bertran Pierre - bertra_b@epitech.eu
 * \version	0.1
 * \date	06/07/2010 18:30:37
 */

#ifndef		POLICYCREATORNEW_H__
# define	POLICYCREATORNEW_H__

template <class T>
class	PolicyCreatorNew
{
	public:
		static T*	create()
		{
			return new T;
		}

		static void	destroy(T* toDelete)
		{
			delete toDelete;
		}
};

template <class T>
class	AbsPolicyCreatorNew
{
	public:
		static T*	create()
		{
			return T::AbsNew();
		}

		static void	destroy(T* toDelete)
		{
			delete toDelete;
		}
};


#endif		// POLICYCREATORNEW_H__
