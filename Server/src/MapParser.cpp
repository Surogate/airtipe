/* 
 * File:   MapParser.cpp
 * Author: Errata
 * 
 * Created on July 19, 2010, 7:13 PM
 */

#include <string>
#include <sstream>

#include "MapParser.h"

MapParser::MapParser(std::string file, Map& map)
: _file(file), _map(map), iterator(0), size(file.size()), lineConsumed(0) {}

bool MapParser::consumeScript() {
    while(peek() && consumeBlanks() && peek())
        if (!consumeLine())
        {
            std::cerr << "error at line " << lineConsumed << std::endl;
            return false;
        }
    return true;
}

bool MapParser::consumeLine() {
    bool ret = Entitydecl()&& char_(';');
    if (ret)
        ++lineConsumed;
    return ret;
}

bool MapParser::Entitydecl() {
    monster neo;
    return (char_('<') && (EntityId(neo._id)) && char_('>'));
}

bool MapParser::EntityId(int& in) {
    if (readText("id:") && readInt(in))
}

bool MapParser:: frameDefine() {
    return true;
}

bool MapParser::consumeBlanks() {
    while (char_(' ') || char_('\n') || char_('\t'));
}

bool MapParser::char_(std::string& in) {
    if (iterator < size)
    {
        in += _file[iterator];
        ++iterator;
        return true;
    }
    return false;
}

bool MapParser::char_(char c, std::string& in) {
    if (peek(c))
    {
        in += _file[iterator];
        ++iterator;
        return true;
    }
    return false;
}

bool MapParser::char_(char from, char to, std::string& in) {
    if (peek(from, to))
    {
        in += _file[iterator];
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

bool MapParser::readText(std::string& text, std::string& in) {
    for (unsigned int i = 0; i < text; i++)
    {
        if (!char_(text[i], in))
            return false;
    }
    return true;
}

bool MapParser::readInt(int& in)
{
    std::string num;
    int sign = 1;
    while (peek('+') || peek('-'))
    {
        if (char_('-'))
            sign = sign * -1;
        else
            char_('+');
    }
    while (char_('0', '9', num));
    if (std::stringstream(num) >> in)
    {
        in = in * sign;
        return true;
    }
    return false;
}