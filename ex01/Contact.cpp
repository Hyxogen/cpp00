#include "Contact.h"

Contact::Contact(std::string first_name,
			std::string last_name,
			std::string nickname,
			std::string phonenum,
			std::string secret)
	: _first_name(first_name),
	_last_name(last_name),
	_nickname(nickname),
	_phone_num(phonenum),
	_secret(secret) {

}

Contact::Contact() {
	_first_name = std::string("");
	_last_name = std::string("");
	_nickname = std::string("");
	_phone_num = std::string("");
	_secret = std::string("");
}

Contact& Contact::operator=(const Contact &other) {
	_first_name = other.first_name();
	_last_name = other.last_name();
	_nickname = other.nickname();
	_phone_num = other.phonenum();
	_secret = other.secret();
	return *this;
}

const std::string& Contact::first_name() const {
	return _first_name;
}

const std::string& Contact::last_name() const {
	return _last_name;
}

const std::string& Contact::nickname() const {
	return _nickname;
}

const std::string& Contact::phonenum() const {
	return _phone_num;
}

const std::string& Contact::secret() const {
	return _secret;
}