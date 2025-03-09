#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;
public:
	AMateria(void);
	AMateria(AMateria const &other);
	virtual ~AMateria(void);
	AMateria &operator=(AMateria const &other);

	AMateria(std::string const & type);

	std::string const & getType(void) const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target) = 0;

};

#endif