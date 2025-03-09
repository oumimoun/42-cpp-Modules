#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "Default ScavTrap constructor called " << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called " << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "Parameterized ScavTrap constructor called " << std::endl;
    _HitPoints = 100;
    _EnergyPoints = 50;
    _AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    ClapTrap::operator=(other);
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}


void ScavTrap::attack(const std::string &target)
{
    if (_HitPoints > 0 && _EnergyPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target << std::endl;
        --_EnergyPoints;
    }
    else
    {
        std::cout << "ScavTrap " << _name << " has insufficient hit points or energy to attack." << std::endl;
    }
}

