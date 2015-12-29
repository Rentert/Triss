//
// Created by Aleksandrov Oleg
//

#include <iostream>
#include "../../Headers/parcer/CpuInfoParser.h"

const std::string dir = "/proc/cpuinfo";

std::string CpuInfoParser::update() {
    std::string parse = readAll(dir);

    std::vector<std::string> vector = splitToLineEnd(parse, 26);
    std::string result = "cpuinfo: [";

    for (int i = 0; i < vector.size() - 1; ++i) {
        result += toJson(vector.at(i)) + ',';
    }

    result += toJson(vector.back()) + "]";

    return result;
}

std::vector<std::string> CpuInfoParser::splitToLineEnd(std::string str, int numb) {
    std::vector<std::string> vector;
    std::string buffer = getEmptyString();
    int numbLineEnd = 0;

    for (int i = 0; i < str.size(); ++i) {
        char ch = str.at(i);
        buffer += ch;

        if (ch == '\n') {
            numbLineEnd++;
            if (numbLineEnd == numb) {
                vector.push_back(buffer);
                buffer = getEmptyString();
                numbLineEnd = 0;
            }
        }
    }
    return vector;
}
