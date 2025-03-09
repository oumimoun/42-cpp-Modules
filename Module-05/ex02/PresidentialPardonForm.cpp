#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {}
PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm("presidentialpardon", 25, 5) , _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) 
	: AForm(other) , _target(other._target)
{}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator = (PresidentialPardonForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}

	return (*this);
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}