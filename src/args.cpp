#include "args.h"

void printHelp() {
    std::cout << "List of available arguments:" << std::endl << "\t-f sorting from file from smallest to largest, result is written to file" << std::endl << "\t-rf sorting from file from largest to smallest, the result is written to a file" << std::endl << "\t-c sort from smallest to largest of the input entered into the console, the result is printed to the console" << std::endl << "\t-rc sorting from largest to smallest of the input data entered into the console, the result is printed to the console" << std::endl;
}