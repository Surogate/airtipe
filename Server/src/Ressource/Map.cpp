/* 
 * File:   Map.cpp
 * Author: Errata
 * 
 * Created on July 19, 2010, 2:16 PM
 */

#include "Map.h"

Map::Map(std::string& mapFile)
: _mapFile(mapFile) {
}

Map::~Map() {
}

void Map::loadMap() {
    std::ifstream _mapScript(_mapFile.c_str(), std::ios::in | std::ios::binary | std::ios::ate);
    std::ifstream::pos_type fileSize = _mapScript.tellg();
    _mapScript.seekg(0, std::ios::beg);
    std::vector<char> bytes(fileSize);
    _mapScript.read(&bytes[0], fileSize);
    _mapScript.close();
    std::string script(bytes.begin(), bytes.end());
}
