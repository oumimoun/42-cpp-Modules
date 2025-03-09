#include "FragTrap.hpp"

int main() {
    FragTrap frag("FragName");
    
    frag.attack("enemy");
    frag.takeDamage(20);
    frag.beRepaired(10);
    frag.highFivesGuys();

    return 0;
}
