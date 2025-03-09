#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::setContact(const std::string &first, const std::string &last, const std::string &nick,
	const std::string &phone, const std::string &secret)
{
	this->_firstName = first;
	this->_lastName = last;
	this->_nickname = nick;
	this->_phoneNumber = phone;
	this->_darkestSecret = secret;
	return;
}

std::string Contact::truncateField(const std::string &field) const
{
	if (field.length() > 10)
		return field.substr(0, 9) + ".";
	return field;
}

void Contact::displaySummary(int index) const
{
	std::cout << std::setw(10) << index << "|"
		<< std::setw(10) << truncateField(this->_firstName) << "|"
		<< std::setw(10) << truncateField(this->_lastName) << "|"
		<< std::setw(10) << truncateField(this->_nickname) << std::endl;
	return;
}

void Contact::displayDetails(void) const
{
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
	return;
}

int Contact::getIndex(void) const
{
	return this->_index;
}

std::string Contact::getFirstName(void) const
{
	return this->_firstName;
}

std::string Contact::getLastName(void) const
{
	return this->_lastName;
}

std::string Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}

void Contact::setIndex(int index)
{
	this->_index = index;
	return;
}

