#include "PhoneBook.h"
#include "Util.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>

void add_contact(PhoneBook &phone_book) {
    Contact contact;
    std::cin >> contact;
    phone_book.add_contact(contact);
    std::cout << "Saved contact!" << std::endl << std::endl;
}

void search(const PhoneBook &phone_book) {
	std::string index_str;
	std::size_t index;
	std::size_t end;

    std::cout << phone_book;

	while (true) {
		index_str = get_line(std::cin, "Index: ");
		try {
			index = ft::stoul(index_str, &end);
		} catch (std::exception &ex) {
			std::cerr << "Invalid index" << std::endl;
			continue;
		}
		if (end < index_str.length()) {
			std::cerr << "Invalid index" << std::endl;
			continue;
		}
		if (index >= phone_book.size()) {
			std::cerr << "Invalid index" << std::endl;
			continue;
		}
		break;
	}
	std::cout << phone_book.at(index) << std::endl;
}

void execute_cmd(const std::string &command, PhoneBook &phone_book) {
    if (command == "ADD") {
        add_contact(phone_book);
    } else if (command == "SEARCH") {
        search(phone_book);
    } else if (command == "EXIT") {
        std::exit(EXIT_SUCCESS);
    }
}

int main() {
    PhoneBook   phone_book;
    std::string line;

    while (true) {
        line = get_line(std::cin, "Command: ");
        execute_cmd(line, phone_book);
    }
    return EXIT_SUCCESS;
}
