#include "sorts.h"
#include "args.h"

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printHelp();
    }
    if (argc > 1) {
        if(argv[1][0] == '-' && argv[1][1] =='c') {
            massSort();
            return 0;
        }
        printHelp();
    }
    return 0;
}
