#include "PhoneBook.h"
#include "Util.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>

#ifndef COLUMN_WIDTH
# define COLUMN_WIDTH 10
#endif

void add_contact(PhoneBook &phone_book) {
    Contact contact;
    std::cin >> contact;
    phone_book.add_contact(contact);
    std::cout << "Saved contact!" << std::endl << std::endl;
}

void search(const PhoneBook &phone_book) {
    std::string index_str;

    std::cout << phone_book;

    /*
while (true) {
    index_str = get_line("Index: ");
    if (!is_all_num(index_str)) {
        std::cerr << "index must contain only digits" << std::endl;
        continue;
    }
}
    */
}

void execute_cmd(const std::string &command, PhoneBook &phone_book) {
    if (command == "ADD") {
        add_contact(phone_book);
    } else if (command == "SEARCH") {
        search(phone_book);
    } else if (command == "EXIT") {
        std::exit(0);
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
