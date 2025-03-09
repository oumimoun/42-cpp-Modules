#include "Intern.hpp"
#include <iostream>

Intern::Intern() 
{}

Intern::~Intern()
{}

Intern::Intern(const Intern &)
{}

Intern &Intern::operator=(const Intern &) 
{
	return *this;
}


AForm *makeShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *makePresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*formCreators[3])(const std::string &) = {makeShrubbery, makeRobotomy, makePresidential};

	for (int i = 0; i < 3; ++i)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	std::cerr << "Error: Form name '" << formName << "' does not exist." << std::endl;
	return NULL;
}

