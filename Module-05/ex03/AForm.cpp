#include "AForm.hpp"

AForm::AForm(void) : _name("_pp") , _isSigned(false) , _gradeToSign(150) , _gradeToExecute(150)
{}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name) , _gradeToSign(gradeToSign) , _gradeToExecute(gradeToExecute)
{
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExecute > 150)
		throw GradeTooHighException();
}


AForm::AForm(AForm const &other) 
	: _name(other._name) , _isSigned(other._isSigned) , _gradeToSign(other._gradeToSign) , _gradeToExecute(other._gradeToExecute)
{}

AForm::~AForm(void) {}

AForm &AForm::operator = (AForm const &other)
{
	if (this !=&other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}


const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form '" << form.getName() << "' ["
        << "Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade to Sign: " << form.getGradeToSign()
        << ", Grade to Execute: " << form.getGradeToExecute() << "]";
    return out;
}


void AForm::execute(Bureaucrat const & executor) const 
{
    if (!_isSigned)
    {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute)
    {
        throw GradeTooLowException();
    }
    this->executeAction();
}

