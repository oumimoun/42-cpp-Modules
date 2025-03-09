#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
    std::string _name;
    int _HitPoints;
    int _EnergyPoints;
    int _AttackDamage;

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator= (const ClapTrap& other);
    virtual ~ClapTrap();

    virtual void attack(const std::string& target);

    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    std::string getName(void) const;
    void setName(const std::string& name);

    int getHitPoints(void) const;
    void setHitPoints(int hitpoints);

    int getEnergyPoints(void) const;
    void setEnergyPoints(int energypoints);

    int getAttackDamage(void) const;
    void setAttackDamage(int attackdamage);


};


#endif