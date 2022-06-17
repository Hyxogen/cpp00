#ifndef FT_STRING
#define FT_STRING

#include <string>

namespace ft {
	std::string to_string(unsigned long value);
}

/* This function is not in the ft namespace because it's not part of the standard library */
std::string &truncate(std::string &str, std::size_t width, char ellips);

#endif /* FT_STRING */
