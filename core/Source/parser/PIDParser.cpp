//
// Created by Aleksandrov Oleg
//

#include <dirent.h>
#include <vector>
#include "../../Headers/parcer/PIDParser.h"

std::vector<std::string> PIDParser::getDir(std::string dir) {
    DIR *dp;
    struct dirent *dirp;

    std::vector<std::string> files;

    if((dp  = opendir(dir.c_str())) == NULL) {
        files.push_back("Can't opening " + dir );
        return files;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(std::string(dirp -> d_name));
    }

    closedir(dp);

    return files;
}

bool PIDParser::isInt(char ch, char numb) {
    return ch == numb;
}

bool PIDParser::isInt(char ch) {
    return isInt(ch, '0') || isInt(ch, '1') ||
           isInt(ch, '2') || isInt(ch, '3') ||
           isInt(ch, '4') || isInt(ch, '5') ||
           isInt(ch, '6') || isInt(ch, '7') ||
           isInt(ch, '8') || isInt(ch, '9');
}

std::string PIDParser::update() {
    std::string result = "[";
    auto files = getDir("/proc/");
    int size = files.size();
    int len = size - 1;
    for (int i = 0; i < size; i++)
    {
        std::string value = files.at(i);
        if (isInt(value.at(0))) {
            std::string str = replaceChar(readAll("/proc/" + value + "/comm"), '\n');
            result += "{ pid:'" + value + "', name:'" + str +"'}";

            result += len != i ? ",\n" : "]";
        }
    }

    return "proc:" + result;
}
