#include "Util.h"

#include <cstdlib>
#include <iostream>
#include <limits>
#include <cerrno>
#include <stdexcept>
#include <limits>

namespace ft {
	unsigned long stoul(const std::string &str, std::size_t *pos, int base) {
		char *end = NULL;
		const char *const begin = str.c_str();
		unsigned long value;

		value = std::strtol(begin, &end, base);
		if (value == std::numeric_limits<unsigned long>::max() && errno == ERANGE) {
			throw std::out_of_range("ft::stoul");
		}
		if (end == begin) {
			throw std::invalid_argument("ft::stoul");
		}
		if (pos != NULL) {
			*pos = static_cast<std::size_t>(end - begin);
		}
		return value;
	}
}

std::string get_line(std::istream &is, const std::string &prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(is, line);
    if (is.eof()) {
        std::exit(0); /* TODO might be better to not exit */
    }
    return line;
}

std::string truncate(std::string str, std::size_t width, char ellips) {
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
