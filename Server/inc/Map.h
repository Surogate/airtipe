/* 
 * File:   Map.h
 * Author: Errata
 *
 * Created on July 19, 2010, 2:16 PM
 */

#ifndef MAP_H
#define	MAP_H

#include <queue>
#include <fstream>
#include "Frame.h"


class Map : private std::queue<Frame> {
public:
    Map(std::string& mapFile);
    virtual ~Map();
    void loadMap();

private:
    std::string _mapFile;
    bool _loaded;
    bool _error;
};

#endif	/* MAP_H */
