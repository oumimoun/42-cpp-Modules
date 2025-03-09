#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void) : _type("")
{
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Parameterized constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other)
{
	std::cout << "Copy AMateria constructor called" << std::endl;
	*this = other;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	std::cout << "AMateria copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return (*this);
}

std::string const& AMateria::getType(void) const
{
	return _type;
}
