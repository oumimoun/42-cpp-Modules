#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("_pp"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator = (Bureaucrat const &other)
{
	if (this != &other)
	{
		// name is const cant be copied
		_grade = other._grade;
	}	
	return (*this);
}

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

std::ostream& operator<<(std::ostream& out , const Bureaucrat& bureaucrat)
{
	out << "bureaucrat name: " << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
        throw GradeTooLowException();
    ++_grade;
}
