#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
public:
    PhoneBook(void);
	~PhoneBook(void);
	void addContact(void);
	void search(void) const;
};

#endif
