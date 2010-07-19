/*!
 * \file	Factory.hpp
 * \brief	Generic template class for making prototype factories for any Object which own a creation/cloning methode
 * \author	Alexis Lucazeau - lucaze_b@epitech.eu
 * \version	0.1
 * \date	07/06/2010 11:38:56 AM
 *
 * more description...
 */

#ifndef			FACTORY_H__
#define			FACTORY_H__

# include		<map>

template
<
	class		AbstractProduct,
	typename	IdentifierType,
	typename	Creator,
	template<typename, class> class FactoryErrorPolicy
>
class Factory : public FactoryErrorPolicy<IdentifierType, AbstractProduct>
{
	public:
		bool Register(const IdentifierType& id, AbstractProduct * newProduct, Creator creator)
		{
			typename AssocMap::const_iterator i = associations_.find(id);
			if (i != associations_.end())
			{
				return (associations_.erase(id) == 1);
			}
			std::pair<AbstractProduct *, Creator> * newPair;
			newPair = new std::pair<AbstractProduct *, Creator >(newProduct, creator);
			return associations_.insert(std::pair< const IdentifierType&, std::pair<AbstractProduct *, Creator > * >(id, newPair)).second;
		}

		bool Unregister(const IdentifierType& id)
		{
			return (associations_.erase(id) == 1);
		}

		AbstractProduct* CreateObject(const IdentifierType& id)
		{
			typename AssocMap::const_iterator i = associations_.find(id);
			if (i != associations_.end())
			{
				return (i->second->first->*(i->second->second))();
			}
			AbstractProduct* pProduct = this->OnUnknownType(id);
			return (pProduct);
		}
	private:
		typedef std::map<IdentifierType, std::pair<AbstractProduct *, Creator > * > AssocMap;
		AssocMap associations_;
};



#endif			// FACTORY_H__
