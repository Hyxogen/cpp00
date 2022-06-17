#include "PhoneBook.h"

#include <stdexcept>

PhoneBook::PhoneBook() : _index(0), _size(0) {

}

PhoneBook::pointer PhoneBook::data() {
	return contacts;
}

PhoneBook::const_pointer PhoneBook::data() const {
	return contacts;
}

PhoneBook::size_type PhoneBook::size() const {
	return _size;
}

PhoneBook::size_type& PhoneBook::size() {
	return _size;
}

PhoneBook::size_type PhoneBook::index() const {
	return _index;
}

PhoneBook::size_type& PhoneBook::index() {
	return _index;
}

PhoneBook::reference PhoneBook::at(PhoneBook::size_type pos) {
	if (!(pos < size()))
		throw std::out_of_range("out of bounds access in PhoneBook");
	return contacts[pos];
}

PhoneBook::const_reference PhoneBook::at(PhoneBook::size_type pos) const {
	if (!(pos < size()))
		throw std::out_of_range("out of bounds access in PhoneBook");
	return contacts[pos];
}

PhoneBook::iterator PhoneBook::begin() {
	return iterator(data());
}

PhoneBook::iterator PhoneBook::end() {
	return iterator(data() + size());
}

PhoneBook::const_iterator PhoneBook::begin() const {
	return const_iterator(data());
}

PhoneBook::const_iterator PhoneBook::end() const {
	return const_iterator(data() + size()); 
}

PhoneBook::const_iterator PhoneBook::cbegin() const {
	return begin();
}

PhoneBook::const_iterator PhoneBook::cend() const {
	return end(); 
}

PhoneBook::reference PhoneBook::operator[](size_type pos) {
	return contacts[pos];
}

PhoneBook::const_reference PhoneBook::operator[](size_type pos) const {
	return contacts[pos];
}

PhoneBook::size_type PhoneBook::increment_index() {
	if (size() < CONTACT_SIZE)
		size() += 1;
	index() = (index() + 1) % CONTACT_SIZE;
	return index();
}

void PhoneBook::add_contact(PhoneBook::const_reference contact) {
	(*this)[index()] = contact;
	increment_index();
}
