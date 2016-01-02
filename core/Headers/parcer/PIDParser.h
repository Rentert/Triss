//
// Created by Aleksandrov Oleg
//

#ifndef TRISS_PROC_H
#define TRISS_PROC_H

#include <iostream>
#include "../../Headers/parcer/AbstractSystemParser.h"
#include <vector>

class PIDParser : public AbstractSystemParser {
public:

    virtual std::string update() override;

private:
    std::vector<std::string> getDir(std::string dir);
    bool isInt(char ch, char numb);
    bool isInt(char ch);
};


#endif //TRISS_PROC_H
