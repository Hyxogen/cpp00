#include "String.h"

#include "Algorithm.h"

#define BASE10_RADIX 10

namespace ft {

    std::string to_string(unsigned long value) {
        std::string result;
        if (value == 0) {
            return std::string("0");
        }
        while (value > 0) {
            result += static_cast<char>((value % BASE10_RADIX) + '0');
            value /= BASE10_RADIX;
        }
        ft::reverse(result.begin(), result.end());
        return (result);
    }

}

std::string &truncate(std::string &str, std::size_t width, char ellips) {
    if (str.length() <= width) {
        return str;
    }
    if (width == 0) {
        str = str.substr(0, 0);
    } else {
        str = str.substr(0, width - 1) + ellips;
    }
    return (str);
}
