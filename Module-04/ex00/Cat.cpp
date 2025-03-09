#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operatpr called" << std::endl;
    if (this != &other)
    {
        this->_type = other.getType();
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}


void Cat::makeSound(void) const 
{
    std::cout << "Meow! Meow!🐈" << std::endl;
}

