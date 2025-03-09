#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern(void);
	Intern(Intern const &other);
	~Intern(void);
	Intern &operator=(Intern const &other);

	AForm* makeForm(const std::string &formName, const std::string &target);

};

#endif