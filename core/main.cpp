#include <iostream>
#include "Headers/parcer/PIDParser.h"
#include "Headers/parcer/ParseExecutor.h"

int main() {
    ParseExecutor executor;

    std::cout << executor.execute();
    return 0;
}