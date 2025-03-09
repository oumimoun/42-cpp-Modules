#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat john("John Cena", 42);
        std::cout << john << std::endl;

        john.incrementGrade();
        std::cout << "After increment: " << john << std::endl;

        john.decrementGrade();
        john.decrementGrade();
        std::cout << "After decrement: " << john << std::endl;

        Bureaucrat boss("Big Boss", -1);
        boss.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat laylow("laylow", 150);
        std::cout << laylow << std::endl;
        laylow.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
