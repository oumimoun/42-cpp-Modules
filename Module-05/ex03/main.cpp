#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *form;

    std::cout << "\n----- Creating a Shrubbery Form -----\n";
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form)
        delete form;

    std::cout << "\n----- Creating a Robotomy Request Form -----\n";
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
        delete form;

    std::cout << "\n----- Creating a Presidential Pardon Form -----\n";
    form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
    if (form)
        delete form;

    std::cout << "\n----- Testing an Invalid Form Name -----\n";
    form = someRandomIntern.makeForm("invalid form", "unknown");
    if (form)
        delete form;

    return 0;
}
