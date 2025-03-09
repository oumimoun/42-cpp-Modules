#include "WrongDog.hpp"

WrongDog::WrongDog()
{
    _type = "WrongDog";
    std::cout << "Default WrongDog constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other)
{
    std::cout << "WrongDog Copy constructor called" << std::endl;
    *this = other;
}

WrongDog& WrongDog::operator=(const WrongDog& other)
{
    std::cout << "WrongDog Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_type = other.getType();
    }
    return *this;
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog Destructor called" << std::endl;
}

void WrongDog::makeSound(void) const
{
    std::cout << "Wrong Woof! Woof! 🌭" << std::endl;
}

