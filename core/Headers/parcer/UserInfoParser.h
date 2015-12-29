//
// Created by Aleksandrov Oleg
//

#ifndef TRISS_USERINFOPARSER_H
#define TRISS_USERINFOPARSER_H

#include <iostream>
#include "AbstractSystemParser.h"

class UserInfoParser : public AbstractSystemParser {
public:
    std::string update();
};


#endif //TRISS_USERINFOPARSER_H
