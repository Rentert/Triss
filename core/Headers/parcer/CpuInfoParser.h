//
// Created by Aleksandrov Oleg
//

#ifndef TRISS_CPUINFOPARSER_H
#define TRISS_CPUINFOPARSER_H

#include <vector>
#include "../parcer/AbstractSystemParser.h"

class CpuInfoParser : public AbstractSystemParser{
public:
    std::string update() override;

private:
    std::vector<std::string> splitToLineEnd(std::string str, int numb);
};


#endif //TRISS_CPUINFOPARSER_H
