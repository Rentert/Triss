//
// Created by Aleksandrov Oleg
//

#include <iostream>
#include <fstream>
#include "../../Headers/parcer/AbstractSystemParser.h"


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
            result += createValue(buffer + ch, "'");
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

    for (int i = 0; i < info.size(); ++i) {
        char ch = info.at(i);
        if (ch == splitChar)
        {
            result[0] = buffer;
            buffer = getEmptyString();
        }
        else
            buffer += ch;
    }

    result[1] = buffer;

    return result;
}

std::string AbstractSystemParser::replaceChar(std::string str, char from) {
    std::string result = getEmptyString();

    for (int i = 0; i < str.size(); ++i) {
        char ch = str.at(i);
        if (ch != from) {
            result += ch;
        }
    }

    return result;
}

std::string AbstractSystemParser::createValue(std::string buffer, std::string endValue) {
    std::string rs = replaceChar(buffer, '\t');
    std::string* array = split(replaceChar(rs, ' '), ':');
    return  "'" + array[0] + "' : '" + array[1] + endValue;
}

std::string AbstractSystemParser::getEmptyString() {
    return "";
}
