/* 
 * File:   MapParser.h
 * Author: Errata
 *
 * Created on July 19, 2010, 7:13 PM
 */

#ifndef MAPPARSER_H
#define	MAPPARSER_H

#include <string>

struct monster {
    int _id;  
};

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
    std::map<int, monster> _monsterList;

    bool consumeLine();
    bool consumeBlanks();
    bool Entitydecl();
    bool EntityId();
    bool frameDefine();
    inline bool peek();
    inline bool peek(char c);
    inline bool peek(char from, char to);
    inline bool char_(std::string& in = std::string());
    inline bool char_(char c, std::string& in = std::string());
    inline bool char_(char from, char to, std::string& in = std::string());
    bool readText(std::string& text, std::string& in = std::string());
    bool readInt(int& in);
};


#endif	/* MAPPARSER_H */

