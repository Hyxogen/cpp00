#ifndef CONTACT_H
#define CONTACT_H
#include <ostream>
#include <string>

class Contact {
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_num;
    std::string _secret;

public:
    Contact(
        const std::string &first_name, const std::string &last_name,
        const std::string &nickname, const std::string &phonenum,
        const std::string &secret);

    Contact();

    Contact(const Contact &other);

    ~Contact();

    Contact &operator=(const Contact &other);

    const std::string &first_name() const;
    const std::string &last_name() const;
    const std::string &nickname() const;
    const std::string &phonenum() const;
    const std::string &secret() const;
};

std::ostream &operator<<(std::ostream &os, const Contact &contact);

#endif
