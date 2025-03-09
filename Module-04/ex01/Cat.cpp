#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
    _type = "Cat";
    std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat Copy assignment operatpr called" << std::endl;
    if (this != &other)
    {
        this->_type = other.getType();
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat Destructor called" << std::endl;
}


void Cat::makeSound(void) const 
{
    std::cout << "Meow! Meow!🐈" << std::endl;
}


const Brain* Cat::getBrain(void)
{
    return _brain;
}

