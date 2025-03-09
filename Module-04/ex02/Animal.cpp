#include "Animal.hpp"


Animal::Animal() : _type("")
{
    std::cout << "Default Animal constructor is called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor is called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other._type;
    }
    return *this;
}

std::string Animal::getType(void) const
{
    return this->_type;
}

