#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        std::cout << "----- TESTING BUREAUCRAT CREATION -----" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat assistant("Assistant", 75);

        std::cout << "\n----- TESTING INVALID BUREAUCRAT CREATION -----" << std::endl;
        try
        {
            Bureaucrat invalid("Invalid", 0);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            Bureaucrat invalid("Invalid", 151);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n----- TESTING GRADE INCREMENTS AND DECREMENTS -----" << std::endl;
        assistant.incrementGrade();
        std::cout << assistant << std::endl;
        assistant.decrementGrade();
        std::cout << assistant << std::endl;

        try
        {
            boss.incrementGrade();
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n----- TESTING SHRUBBERY CREATION FORM -----" << std::endl;
        ShrubberyCreationForm shrubbery("home");
        boss.signForm(shrubbery);
        boss.executeForm(shrubbery);

        std::cout << "\n----- TESTING ROBOTOMY REQUEST FORM -----" << std::endl;
        RobotomyRequestForm robotomy("target");
        boss.signForm(robotomy);
        for (int i = 0; i < 3; ++i)
        {
            boss.executeForm(robotomy);
        }

        std::cout << "\n----- TESTING PRESIDENTIAL PARDON FORM -----" << std::endl;
        PresidentialPardonForm pardon("criminal");
        boss.signForm(pardon);
        boss.executeForm(pardon);

        std::cout << "\n----- TESTING UNSIGNED FORM EXECUTION -----" << std::endl;
        try
        {
            ShrubberyCreationForm unsignedForm("office");
            assistant.executeForm(unsignedForm);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "\n----- TESTING INSUFFICIENT GRADE FOR SIGNING AND EXECUTION -----" << std::endl;
        try
        {
            ShrubberyCreationForm lowGradeForm("garden");
            assistant.signForm(lowGradeForm);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try
        {
            ShrubberyCreationForm lowGradeExec("garden");
            boss.signForm(lowGradeExec);
            assistant.executeForm(lowGradeExec);
        }
        catch (std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << "Unexpected Exception: " << e.what() << std::endl;
    }

    return 0;
}
