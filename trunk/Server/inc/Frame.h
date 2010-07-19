/* 
 * File:   Frame.h
 * Author: Errata
 *
 * Created on July 19, 2010, 2:17 PM
 */

#ifndef FRAME_H
#define	FRAME_H

#include <map>

#include "AEntity.h"


struct Frame {
    unsigned int _height;
    unsigned int _width;
    AEntity<> _ceil;
    AEntity<> _floor;
    std::map<unsigned int, Position> _monster;
    std::map<unsigned int, Position> _items;
};

#endif	/* FRAME_H */

