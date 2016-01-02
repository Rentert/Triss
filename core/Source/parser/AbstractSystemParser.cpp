//
// Created by Aleksandrov Oleg
//

#include <iostream>
#include <fstream>
#include "../../Headers/parcer/AbstractSystemParser.h"

static const std::string singleQuotes = "'";

std::string AbstractSystemParser::readAll(std::string dir) {
    std::ifstream stream(dir);
    std::string str((std::istreambuf_iterator<char>(stream) ),
                    (std::istreambuf_iterator<char>() ));

    stream.close();

    return str;
}

std::string AbstractSystemParser::toJson(std::string info) {
    std::string result = "{";

    std::string buffer = getEmptyString();

    int size = info.size();
    int len = size - 1;

    for (int i = 0; i < size; ++i) {
        char ch = info.at(i);
        if (i == len)
            result += createValue(buffer + ch, singleQuotes);
        else if (ch == '\n') {
            result += createValue(buffer, "',\n");
            buffer = getEmptyString();
        }
        else
            buffer += ch;
    }

    return result + '}';
}

std::string *AbstractSystemParser::split(std::string info, char splitChar) {
    std::string* result = new std::string[2];
    std::string buffer = getEmptyString();

    for (const auto &value : info) {
        if (value == splitChar)
        {
            result[0] = buffer;
            buffer = getEmptyString();
        }
        else
            buffer += value;
    }

    result[1] = buffer;

    return result;
}

std::string AbstractSystemParser::replaceChar(std::string str, char from) {
    std::string result = getEmptyString();

    for (const auto &value : str) {
        if (value != from) {
            result += value;
        }
    }

    return result;
}

std::string AbstractSystemParser::createValue(std::string buffer, std::string endValue) {
    auto rs = replaceChar(buffer, '\t');
    auto array = split(replaceChar(rs, ' '), ':');

    auto first = array[0];
    auto second = array[1];

    return check(first)? "" :
           first + ": '" + (check(second)? "None" : second) + endValue;
}

std::string AbstractSystemParser::getEmptyString() {
    return "";
}


std::string AbstractSystemParser::addSingleQuotes(std::string str) {
    return singleQuotes + str + singleQuotes;
}

bool AbstractSystemParser::check(std::string str) {
    return str == " " || str.size() == 0;
}
