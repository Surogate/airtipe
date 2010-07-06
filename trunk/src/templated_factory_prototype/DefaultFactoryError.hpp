/*!
 * \file	DefaultFactoryError.hpp
 * \brief	
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/06/2010 04:03:09 PM
 *
 * more description...
 */

#ifndef		DEFAULTFACTORYERROR_H__
#define		DEFAULTFACTORYERROR_H__

#include <iostream>

template <class IdentifierType, class ProductType>
class DefaultFactoryError
{
	public:
		class Exception : public std::exception
		{
			public:
				Exception(const IdentifierType& unknownId)
					: unknownId_(unknownId)
				{
				}
				virtual const char* what()
				{
					return "Unknown object type passed to Factory.";
				}
				const IdentifierType GetId()
				{
					return unknownId_;
				};
			private:
				IdentifierType unknownId_;
		};
	protected:
		static ProductType* OnUnknownType(const IdentifierType& id)
		{
			throw Exception(id);
		}
};

#endif		// DEFAULTFACTORYERROR_H__
