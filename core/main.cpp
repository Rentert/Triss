#include <iostream>
#include "Headers/parcer/PIDParser.h"
#include "Headers/parcer/ParseExecutor.h"


int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::cout << argv[i] << "\n";
    }
//    system("clear");
//    std::cout << "fuck";
//    while (true) {
//        PIDParser parser;
//
//        std::cout << parser.update();
//
//        std::cin.get();
//            system("clear");
//    }
    return 0;
}