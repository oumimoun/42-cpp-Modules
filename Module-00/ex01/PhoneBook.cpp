#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    std::cout << "Hello and welcome to PhoneBook" << std::endl;
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}

int isNumeric(const std::string &str)
{
    int i = 0;
    while (str[i])
    {
        if (std::isdigit(str[i]) == 0)
            return 0;
        i++;
    }
    return 1;
}

int is_all_spaces(const std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isspace(str[i]))
            return 0;
    }
    return 1;
}

std::string reduce_spaces(const std::string &str)
{
    std::string result;
    bool in_whitespace = false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (std::isspace(str[i]))
        {
            if (!in_whitespace)
            {
                result += ' ';
                in_whitespace = true;
            }
        }
        else
        {
            result += str[i];
            in_whitespace = false;
        }
    }
    return result;
}

void PhoneBook::addContact(void)
{
    std::string first, last, nick, phone, secret;
    static int i;

    std::cout << "Enter first name: ";
    std::getline(std::cin, first);
    first = reduce_spaces(first);
    if (first.empty() || is_all_spaces(first))
    {
        std::cout << "First name cannot be empty." << std::endl;
        return;
    }
    std::cout << "Enter last name: ";
    std::getline(std::cin, last);
    last = reduce_spaces(last);
    if (last.empty() || is_all_spaces(last))
    {
        std::cout << "Last name cannot be empty." << std::endl;
        return;
    }
    std::cout << "Enter nickname: ";
    std::getline(std::cin, nick);
    nick = reduce_spaces(nick);
    if (nick.empty() || is_all_spaces(nick))
    {
        std::cout << "Nickname cannot be empty." << std::endl;
        return;
    }
    std::cout << "Enter phone number: ";
    std::getline(std::cin, phone);
    phone = reduce_spaces(phone);
    if (phone.empty() || is_all_spaces(phone))
    {
        std::cout << "Phone number cannot be empty." << std::endl;
        return;
    }
    if (!isNumeric(phone))
    {
        std::cout << "Phone number must be numeric." << std::endl;
        return;
    }
    if (phone.length() != 10)
    {
        std::cout << "Phone number must be numeric 10 digits long." << std::endl;
        return;
    }
    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, secret);
    secret = reduce_spaces(secret);
    if (secret.empty() || is_all_spaces(secret))
    {
        std::cout << "Darkest secret cannot be empty." << std::endl;
        return;
    }
    _contacts[i % 8].setContact(first, last, nick, phone, secret);
    i++;
    std::cout << "Contact added successfully!" << std::endl;
}


void PhoneBook::search(void) const
{
    std::string str = "";
    int index = -1;

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    
    bool contactExists = false;

    for (int i = 0; i < 8; i++)
    {
        if (_contacts[i].getFirstName().empty())
            break;
        _contacts[i].displaySummary(i + 1);
        contactExists = true;
    }
    if (!contactExists)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << "Enter the index of the contact you want to display: ";
    std::getline(std::cin, str);

    if (!isNumeric(str) || str.length() != 1 || str.empty())
    {
        std::cerr << "Invalid index. Please enter a number between 1 and 8." << std::endl;
        return;
    }
    index = atoi(str.c_str());

    if (index < 1 || index > 8 || _contacts[index - 1].getFirstName().empty())
    {
        std::cerr << "Invalid index. Please enter a number corresponding to an existing contact." << std::endl;
        return;
    }
    _contacts[index - 1].displayDetails();
}

