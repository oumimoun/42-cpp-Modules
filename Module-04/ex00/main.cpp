#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

int main()
{
    {
        std::cout << "------------------------" << std::endl;
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    {
        std::cout << "------------------------" << std::endl;
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *j = new WrongDog();
        const WrongAnimal *i = new WrongCat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    {
        std::cout << "------------------------" << std::endl;
        Animal animal;
        WrongAnimal wronganimal;

        Dog dog;
        Cat cat;
        WrongDog wrongdog;
        WrongCat wrongcat;
        std::cout << dog.getType() << std::endl;
        std::cout << cat.getType() << std::endl;
        std::cout << wrongdog.getType() << std::endl;
        std::cout << wrongcat.getType() << std::endl;
        animal.makeSound();
        dog.makeSound();
        cat.makeSound();
        wronganimal.makeSound();
        wrongcat.makeSound();
        wrongdog.makeSound();
    }
    return 0;
}
