#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(Bureaucrat const &other);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &other);

	const std::string& getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};

	void incrementGrade();
    void decrementGrade();

	void signForm(AForm& form) const;

	void executeForm(AForm const & form) const;

};


std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif