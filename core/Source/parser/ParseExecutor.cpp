//
// Created by Aleksandrov Oleg
//

#include "../../Headers/parcer/ParseExecutor.h"
#include "../../Headers/parcer/CpuInfoParser.h"
#include "../../Headers/parcer/MemInfoParser.h"
#include "../../Headers/parcer/UserInfoParser.h"

ParseExecutor::ParseExecutor() {
    parsers.push_back(new UserInfoParser);
    parsers.push_back(new CpuInfoParser);
    parsers.push_back(new MemInfoParser);
}

std::string ParseExecutor::execute() {
    std::string result = getOpenString();
    for (int i = 0; i < parsers.size() - 1; ++i)
        result += parsers.at(i) -> update() + ",";

    result += parsers.back() -> update();

    return result + getCloseString();
}

std::string ParseExecutor::getOpenString() const {
    return "{";
}

std::string ParseExecutor::getCloseString() const {
    return "}";
}
