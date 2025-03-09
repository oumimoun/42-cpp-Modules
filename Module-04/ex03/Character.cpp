#include "Character.hpp"

Character::Character(void) 
{
	std::cout << "Default Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(Character const &other)
{
	std::cout << "Character Copy constructor is called" << std::endl;
	*this = other;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
		}
		_inventory[i] = NULL;
	}
}

Character &Character::operator = (Character const &other)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] != NULL)
			{
				delete _inventory[i];
			}
			_inventory[i] = NULL;
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}


Character::Character(const std::string &name ) : _name(name)
{
	std::cout << "Parameterized Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

std::string const& Character::getName() const 
{
	return _name;
}

void Character::use(int index, ICharacter& target)
{
	if (index >= 0 && index < 4 && _inventory[index] != NULL)
	{
		_inventory[index]->use(target);
	}
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return;

	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}

}

void Character::unequip(int index)
{
	if (index >= 0 && index < 4)
	{
		_inventory[index] = NULL;
	}
}


