#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
    std::cout << "=== Animal Creation and Destruction Tests ===" << std::endl;

    const Animal *j = new Dog();
    const Animal *i = new Cat();
    j->makeSound();
    i->makeSound();
    delete j;
    delete i;

    std::cout << "\n=== Deep Copy Tests ===" << std::endl;

    Dog originalDog;
    originalDog.makeSound();

    Dog copiedDog = originalDog;
    copiedDog.makeSound();

    Cat originalCat;
    originalCat.makeSound();

    Cat copiedCat = originalCat;
    copiedCat.makeSound();

    std::cout << "\n=== Sheet Test ===" << std::endl;

    Dog basic;
    {
        Dog tmp = basic;
        basic.makeSound();
        tmp.makeSound();
    }

    std::cout << "All tests completed." << std::endl;
    return 0;
}
