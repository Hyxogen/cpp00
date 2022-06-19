#include "Algorithm.h"
#include "PhoneBook.h"
#include "String.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>

#ifndef COLUMN_WIDTH
# define COLUMN_WIDTH 10
#endif

std::string get_line(const std::string &prompt) {
    std::string line;
    std::cout << prompt;
    std::getline(std::cin, line);
    if (std::cin.eof()) {
        std::exit(0);
    }
    return line;
}

void add_contact(PhoneBook &phone_book) {
    Contact contact = Contact(
        get_line("First name: "), get_line("Last name: "),
        get_line("Nickname: "), get_line("Phonenumber: "),
        get_line("Darkest secret: "));
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
        line = get_line("Command: ");
        execute_cmd(line, phone_book);
    }
    return EXIT_SUCCESS;
}
