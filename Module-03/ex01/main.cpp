#include "ScavTrap.hpp"

int main() {
    ScavTrap st("ScavTrapName");

    st.attack("Enemy");
    st.takeDamage(30);
    st.beRepaired(20);
    st.guardGate();

    return 0;
}
