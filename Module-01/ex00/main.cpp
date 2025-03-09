#include "Zombie.hpp"

int main() {
    Zombie* heapZombie;

    heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    delete heapZombie;

    randomChump("StackZombie");

    return 0;
}

