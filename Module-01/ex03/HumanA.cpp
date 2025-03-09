#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {
    std::cout << "HumanA Constructor Called" << std::endl;
}

HumanA::~HumanA()
{
    std::cout << "HumanA Destructor Called" << std::endl;
}

void HumanA::attack() const {
    std::cout << name << " attacks with his " << weapon.getType() << std::endl;
}
