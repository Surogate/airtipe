/*!
 * \file	NoThrowFactoryError.hpp
 * \brief	
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/06/2010 04:51:03 PM
 *
 * more description...
 */

#ifndef			NOTHROWFACTORYERROR_H__
#define			NOTHROWFACTORYERROR_H__

template <class IdentifierType, class ProductType>
class NoThrowFactoryError
{
	protected:
		static ProductType* OnUnknownType(const IdentifierType& id)
		{
			return (new ProductType);
		}
};

#endif			// NOTHROWFACTORYERROR_H__
