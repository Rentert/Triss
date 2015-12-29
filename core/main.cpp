#include <iostream>
#include "Headers/parcer/ParseExecutor.h"
#include "Headers/parcer/UserInfoParser.h"

int main() {

    ParseExecutor executor;

    std::cout << executor.execute();
    return 0;
}