#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotom", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("robotomy", 72, 45) , _target(target) {}


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other) , _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator = (RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		_target = other._target;
	}
	return (*this);
}

void  RobotomyRequestForm::executeAction() const 
{
	std::srand(std::time(NULL));
	std::cout << "Drilling noises 🔉🔉🔉🔉" << std::endl;
	if (std::rand() % 2 == 1)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy of " << _target << " failed!" << std::endl;

}


