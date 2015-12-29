//
// Created by Aleksandrov Oleg
//

#ifndef TRISS_PARSEEXECUTOR_H
#define TRISS_PARSEEXECUTOR_H


#include <iostream>
#include <vector>
#include "AbstractSystemParser.h"

class ParseExecutor {
public:
    ParseExecutor();
    std::string execute();

private:
    std::vector<AbstractSystemParser*> parsers;
};


#endif //TRISS_PARSEEXECUTOR_H
