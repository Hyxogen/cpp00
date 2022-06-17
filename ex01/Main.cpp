#include "PhoneBook.h"
#include "algorithm.h"
#include "string.h"

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

void print_column(std::string str) {
    std::cout << '|';
    std::cout << std::setw(COLUMN_WIDTH) << truncate(str, COLUMN_WIDTH, '.');
}

void print_separator() {
    std::cout << "---------------------------------------------" << std::endl;
}

void print_table_entry(
    const std::string &str0, const std::string &str1, const std::string &str2,
    const std::string &str3) {
    print_separator();
    print_column(str0);
    print_column(str1);
    print_column(str2);
    print_column(str3);
    std::cout << "|" << std::endl;
}

void display_contacts(const PhoneBook &phone_book) {
    PhoneBook::size_type ndx = 0;

    print_table_entry("index", "first name", "last name", "nickname");
    for (PhoneBook::const_iterator it = phone_book.cbegin();
         it != phone_book.cend(); ++it) {
        print_table_entry(
            ft::to_string(ndx), it->first_name(), it->last_name(),
            it->nickname());
        ndx++;
    }
    print_separator();
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
    display_contacts(phone_book);
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
