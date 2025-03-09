#include "ClapTrap.hpp"

int main() {
    ClapTrap ct1("Sigma");

    ct1.attack("Beta");
    ct1.takeDamage(4);
    ct1.beRepaired(3);

    ClapTrap ct2 = ct1;
    ct2.takeDamage(5);
    
    ClapTrap ct3;
    ct3 = ct1;

    return 0;
}
