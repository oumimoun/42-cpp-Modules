#include "Cure.hpp"

Cure::Cure(void) :AMateria("cure")
{
	std::cout << "Default Cure constructor is called" << std::endl;
}

Cure::Cure(Cure const &other)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator = (Cure const &other)
{
	std::cout << "Cure copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return (*this);
}

AMateria* Cure::clone(void) const 
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

