#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Copy Constuctor called" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "assignemet operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
        
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}

