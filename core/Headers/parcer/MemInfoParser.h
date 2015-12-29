//
// Created by Aleksandrov Oleg
//

#ifndef TRISS_MEMINFOPARCER_H
#define TRISS_MEMINFOPARCER_H

#include "AbstractSystemParser.h"

class MemInfoParser : public AbstractSystemParser {
public:
    std::string update();
};


#endif //TRISS_MEMINFOPARCER_H
