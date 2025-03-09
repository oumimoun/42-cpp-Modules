#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("HABBAT");

    diamond.attack("SOFIA");
    diamond.takeDamage(20);
    diamond.beRepaired(10);
    diamond.highFivesGuys();
    diamond.guardGate();
    diamond.whoAmI();

    return 0;
}
