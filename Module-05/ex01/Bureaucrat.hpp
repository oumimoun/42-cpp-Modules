#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

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

	void signForm(Form& form);

};


std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif