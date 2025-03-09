#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "Dfault MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	std::cout << "Copy MateriaSource constructor called" << std::endl;
	*this = copy;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] != NULL)
			delete _templates[i];
		_templates[i] = NULL;
	}
}

MateriaSource const	&MateriaSource::operator = (MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete _templates[i];
			if (other._templates[i] != NULL)
			{
				_templates[i] = other._templates[i]->clone();
			}
			else 
				_templates[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] == NULL)
		{
			_templates[i] = m;
			return;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_templates[i] != NULL && _templates[i]->getType() == type)
		{
			return _templates[i]->clone();
		}
	}
	return 0;
}
