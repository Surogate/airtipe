/* 
 * File:   MapParser.h
 * Author: Errata
 *
 * Created on July 19, 2010, 7:13 PM
 */

#ifndef MAPPARSER_H
#define	MAPPARSER_H

#include <string>

class MapParser {
public:
    MapParser(std::string file, Map& map);
    bool consumeScript();

private:
    std::string& _file;
    unsigned int iterator;
    unsigned int size;
    Map& _map;
    int lineConsumed;

    bool consumeLine();
    bool consumeBlanks();
    bool Entitydecl();
    bool frameDefine();
    inline bool char_();
    inline bool char_(char c);
    inline bool char_(char from, char to);
    inline bool peek();
    inline bool peek(char c);
    inline bool peek(char from, char to);
};


#endif	/* MAPPARSER_H */

