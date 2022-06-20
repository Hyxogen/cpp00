#ifndef UTIL_H
#define UTIL_H

#include <istream>
#include <string>

#define FT_BASE10_RADIX 10

namespace ft {
    unsigned long stoul(
        const std::string &str, std::size_t *pos = NULL,
        int base = FT_BASE10_RADIX);
}

std::string get_line(std::istream &is, const std::string &prompt);

std::string truncate(std::string str, std::size_t width, char ellips);

#endif
