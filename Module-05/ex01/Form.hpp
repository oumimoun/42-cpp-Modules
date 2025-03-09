#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const	std::string	_name;
	bool	_isSigned;
	const	int	_gradeToSign;
	const	int	_gradeToExecute;
public:
	Form(void);
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(Form const &other);
	~Form(void);
	Form &operator=(Form const &other);

	const std::string& getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool isSigned() const;

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "GradeTooHighException: Grade is too high!";
			}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "GradeTooLowException: Grade is too low!";
			}
	};


	void beSigned(const Bureaucrat& bureaucrat);

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif