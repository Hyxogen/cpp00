#include "Contact.h"

#include "Util.h"

Contact::Contact(
    const std::string &first_name, const std::string &last_name,
    const std::string &nickname, const std::string &phonenum,
    const std::string &secret) :
    _first_name(first_name),
    _last_name(last_name), _nickname(nickname), _phone_num(phonenum),
    _secret(secret) { }

Contact::Contact() {
    _first_name = std::string("");
    _last_name  = std::string("");
    _nickname   = std::string("");
    _phone_num  = std::string("");
    _secret     = std::string("");
}

Contact::Contact(const Contact &other) {
    *this = other;
}

Contact::~Contact() { }

Contact &Contact::operator=(const Contact &other) {
    if (this == &other) {
        return *this;
    }
    _first_name = other.first_name();
    _last_name  = other.last_name();
    _nickname   = other.nickname();
    _phone_num  = other.phonenum();
    _secret     = other.secret();
    return *this;
}

const std::string &Contact::first_name() const {
    return _first_name;
}

const std::string &Contact::last_name() const {
    return _last_name;
}

const std::string &Contact::nickname() const {
    return _nickname;
}

const std::string &Contact::phonenum() const {
    return _phone_num;
}

const std::string &Contact::secret() const {
    return _secret;
}

std::ostream &operator<<(std::ostream &os, const Contact &contact) {
    os << "First name: " << contact.first_name() << std::endl
       << "Last name: " << contact.last_name() << std::endl
       << "Nickname: " << contact.nickname() << std::endl
       << "Phone number: " << contact.phonenum() << std::endl
       << "Darkest secret:" << contact.secret();
    return os;
}

std::istream &operator>>(std::istream &is, Contact &contact) {
    contact._first_name = get_line(is, "First name: ");
    contact._last_name  = get_line(is, "Last name: ");
    contact._nickname   = get_line(is, "Nickname: ");
    contact._phone_num  = get_line(is, "Phone number: ");
    contact._secret     = get_line(is, "Darkest secret: ");
    return is;
}
