#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) : name(name) {
    std::cout << "Zombie " << name << " is born." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << name << " is dead." << std::endl;
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
