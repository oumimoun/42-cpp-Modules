#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <cstdlib>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{

private:
	const	std::string	_name;
	bool	_isSigned;
	const	int	_gradeToSign;
	const	int	_gradeToExecute;

public:
	AForm(void);
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(AForm const &other);
	virtual ~AForm(void);
	AForm &operator=(AForm const &other);

	const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

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

	class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw()
			{
				return "FormNotSignedException: Form is not signed!";
			}
	};


	void beSigned(const Bureaucrat& bureaucrat);

	void execute(Bureaucrat const & executor) const;

	virtual void executeAction() const = 0;

};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
