//
// Created by Aleksandrov Oleg
//

#include <iostream>
#include "../../Headers/parcer/MemInfoParser.h"

const std::string dir = "/proc/meminfo";

std::string MemInfoParser::update() {
    return "'meminfo': " + toJson(readAll(dir));
}
