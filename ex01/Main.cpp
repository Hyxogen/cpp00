#include "PhoneBook.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

#ifndef COLUMN_WIDTH
# define COLUMN_WIDTH 10
#endif

std::string get_line(std::string prompt) {
	std::string line;
	std::cout << prompt;
	std::getline(std::cin, line);
	if (std::cin.eof()) {
		std::exit(0);
	}
	return line;
}

std::string& truncate(std::string &str, std::size_t width, char ellips) {
	if (str.length() <= width)
		return str;
	if (width == 0)
		str = str.substr(0, 0);
	else
		str = str.substr(0, width - 1) + ellips;
	return (str);
}

std::string to_string(unsigned long value) {
	std::string result;
	if (value == 0)
		return std::string("0");

	while (value > 0) {
		result = static_cast<char>((value % 10) + '0') + result;
		value /= 10;
	}
	return (result);
}

void print_column(std::string str) {
	std::cout << '|';
	std::cout << std::setw(COLUMN_WIDTH) << truncate(str, COLUMN_WIDTH, '.');
}

void print_separator() {
	std::cout << "---------------------------------------------" << std::endl;
}

void print_table_entry(const std::string &str0, const std::string &str1,
						const std::string &str2, const std::string &str3) {
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
	for (PhoneBook::const_iterator it = phone_book.cbegin(); it != phone_book.cend(); ++it) {
		print_table_entry(to_string(ndx), it->first_name(), it->last_name(), it->nickname());
		ndx++;
	}
	print_separator();
}

void add_contact(PhoneBook &phone_book) {
	Contact contact = Contact(
				get_line("First name: "),
				get_line("Last name: "),
				get_line("Nickname: "),
				get_line("Phonenumber: "),
				get_line("Darkest secret: "));
	phone_book.add_contact(contact);
	std::cout << "Saved contact!" << std::endl << std::endl;
}

void search(const PhoneBook &phone_book) {
	display_contacts(phone_book);
}

void execute_cmd(std::string command, PhoneBook &phone_book) {
	if (command == "ADD") {
		add_contact(phone_book);
	} else if (command == "SEARCH") {
		search(phone_book);
	} else if (command == "EXIT") {
		std::exit(0);
	}
}

int main() {
	PhoneBook phone_book;
	std::string line;

	while (1) {
		line = get_line("Command: ");
		execute_cmd(line, phone_book);
	}
	return 0;
}
