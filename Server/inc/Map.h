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
    void AddFrame(Frame&);

private:
    std::string _mapFile;
    bool _error;
    std::vector<char> bytes;
    unsigned int iterator;
};

struct parser {
    std::string& _file;
    unsigned int iterator;
    unsigned int size;

    bool parseFile(Map& toMap);
};

#endif	/* MAP_H */
