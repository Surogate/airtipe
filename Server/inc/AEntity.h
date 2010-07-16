/* 
 * File:   AEntity.hpp
 * Author: Errata
 *
 * Created on July 12, 2010, 3:16 PM
 */

#ifndef _AENTITY_HPP
#define	_AENTITY_HPP

#include "MovementPolicy.h"
#include "NoMovement.h"



template< class MvmPolicy = class NoMovement >
class AEntity : private MvmPolicy {
public:
    AEntity(const Position& init, const Position& direction = Position(), const int velocity = 0);

protected:
    unsigned int _id;
    unsigned int _width;
    unsigned int _height;
    int _pv;
};

#endif	/* _AENTITY_HPP */

