#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat manager("Manager", 10);
        Form validForm("ValidForm", 15, 20);

        std::cout << manager << std::endl;
        std::cout << validForm << std::endl;

        manager.signForm(validForm);
        std::cout << validForm << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat employee("employee", 42);
        Form invalidForm("Invalid Form", 2, 150);

        std::cout << employee << std::endl;
        std::cout << invalidForm << std::endl;

        employee.signForm(invalidForm);
        std::cout << invalidForm << std::endl;

        Bureaucrat employee2("employee2", 0);

    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
