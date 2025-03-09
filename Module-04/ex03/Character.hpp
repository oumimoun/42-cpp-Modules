#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	AMateria* _inventory[4];
public:
	Character(void);
	Character(Character const &other);
	~Character(void);
	Character &operator=(Character const &other);

	Character(const std::string &name);

	std::string const& getName() const;
	void use(int index, ICharacter& target);
	void equip(AMateria* m);
	void unequip(int index);

};

#endif

