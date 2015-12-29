//
// Created by Aleksandrov Oleg
//

#include "../../Headers/parcer/UserInfoParser.h"

const std::string dir = "/proc/sys/kernel/hostname";

std::string UserInfoParser::update() {
    std::string result = replaceChar(readAll(dir), '\n');
    return "'hostname': '" + result + "'";
}
