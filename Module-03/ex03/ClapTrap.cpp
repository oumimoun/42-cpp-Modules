#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _HitPoints(10), _EnergyPoints(10), _AttackDamage(0)
{
    std::cout << "Parameterized ClapTrap Constructor called" << std::endl;
    _name = name;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        _name = other.getName();
        _HitPoints = other.getHitPoints();
        _EnergyPoints = other.getEnergyPoints();
        _AttackDamage = other.getAttackDamage();
    }
    return *this;
}

std::string ClapTrap::getName(void) const
{
    return this->_name;
}

void ClapTrap::setName(const std::string &name)
{
    this->_name = name;
}

int ClapTrap::getHitPoints() const
{
    return this->_HitPoints;
}

void ClapTrap::setHitPoints(int hitpoints)
{
    this->_HitPoints = hitpoints;
}

int ClapTrap::getEnergyPoints() const
{
    return this->_EnergyPoints;
}

void ClapTrap::setEnergyPoints(int energypoints)
{
    this->_EnergyPoints = energypoints;
}

int ClapTrap::getAttackDamage(void) const
{
    return this->_AttackDamage;
}

void ClapTrap::setAttackDamage(int attackdamage)
{
    this->_AttackDamage = attackdamage;
}

void ClapTrap::attack(const std::string &target)
{
    if (_HitPoints > 0 && _EnergyPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target << std::endl;
        --_EnergyPoints;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " has insufficient hit points or energy to attack." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_HitPoints > 0)
    {
        _HitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining hit points: " << _HitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " is already at 0 hit points and cannot take more damage." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_HitPoints > 0 && _EnergyPoints > 0)
    {
        _HitPoints += amount;
        --_EnergyPoints;
        std::cout << "ClapTrap " << _name << " repairs itself, gaining " << amount << " hit points! Current hit points: " << _HitPoints << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << _name << " has insufficient hit points or energy to repair." << std::endl;
    }
}
