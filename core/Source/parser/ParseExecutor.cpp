//
// Created by Aleksandrov Oleg
//

#include "../../Headers/parcer/ParseExecutor.h"
#include "../../Headers/parcer/CpuInfoParser.h"
#include "../../Headers/parcer/MemInfoParser.h"
#include "../../Headers/parcer/UserInfoParser.h"
#include "../../Headers/parcer/PIDParser.h"

ParseExecutor::ParseExecutor() {
    parsers.push_back(new UserInfoParser);
    parsers.push_back(new CpuInfoParser);
    parsers.push_back(new MemInfoParser);
    parsers.push_back(new PIDParser);
}

std::string ParseExecutor::execute() {
    std::string result = getOpenString();
    auto back = parsers.back();
    parsers.pop_back();

    for (const auto &value : parsers)
        result += value -> update() + ",";

    result += back -> update();

    return result + getCloseString();
}

std::string ParseExecutor::getOpenString() const {
    return "{";
}

std::string ParseExecutor::getCloseString() const {
    return "}";
}
