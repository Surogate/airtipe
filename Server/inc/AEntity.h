/* 
 * File:   AEntity.hpp
 * Author: Errata
 *
 * Created on July 12, 2010, 3:16 PM
 */

#ifndef _AENTITY_HPP
#define	_AENTITY_HPP

#include "MovementPolicy.hpp"

template< class MovementPolicy = NoMovement >
class AEntity : private MovementPolicy {
protected:
    unsigned int _id;
    unsigned int _width;
    unsigned int _height;
    int _pv;
};

#endif	/* _AENTITY_HPP */

