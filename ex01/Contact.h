#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>

struct Contact {
    /* Usually I would make these variables private, but I really wanted to use
     * the stream extraction operator (<<) and I wasn't allowed to use the
     * friend keyword in this subject, so I've made it public. I did keep the
     * underscore at the beginning to hint that this isn't part of the public
     * interface */
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_num;
    std::string _secret;

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
/* Like said above in contact class, I usually would make this function a friend
 * of Contact */
std::istream &operator>>(std::istream &is, Contact &contact);

#endif
