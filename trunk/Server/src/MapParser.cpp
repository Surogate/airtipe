/* 
 * File:   MapParser.cpp
 * Author: Errata
 * 
 * Created on July 19, 2010, 7:13 PM
 */

#include <string>

#include "MapParser.h"

MapParser::MapParser(std::string file, Map& map)
: _file(file), _map(map), iterator(0), size(file.size()), lineConsumed(0) {}

bool MapParser::consumeScript() {
    while(peek() && consumeBlanks() && peek())
        if (!consumeLine())
        {
            
            return false;
        }
    return true;
}

bool MapParser::consumeLine() {
    bool ret = (Entitydecl() || frameDefine()) && char_(';');
    if (ret)
        ++lineConsumed;
    return ret;
}

bool MapParser::Entitydecl() {
    return true;
    
}

bool MapParser:: frameDefine() {
    return true;
}

bool MapParser::consumeBlanks() {
    while (char_(' ') || char_('\n') || char_('\t'));
}

bool MapParser::char_() {
    if (iterator < size)
    {
        ++iterator;
        return true;
    }
    return false;
}

bool MapParser::char_(char c) {
    if (peek(c))
    {
        ++iterator;
        return true;
    }
    return false;
}

bool MapParser::char_(char from, char to) {
    if (peek(from, to))
    {
        ++iterator;
        return true;
    }
    return false;
}

bool MapParser::peek(char c) {
    return (iterator < size && peek(c));
}

bool MapParser::peek(char from, char to) {
    return (iterator < size && _file[iterator] <= to && _file[iterator] >= from);
}

bool MapParser::peek() {
    return (iterator < size);
}