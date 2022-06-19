#include "Util.h"

#include <cstdlib>
#include <iostream>

std::string get_line(std::istream &is, const std::string &prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(is, line);
    if (is.eof()) {
        std::exit(0); /* TODO might be better to not exit */
    }
    return line;
}
