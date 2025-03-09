#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}

	return (*this);
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		throw std::ios_base::failure("Failed to open file");
	}
	file << "          .     .  .      +     .      .          .\n";
	file << "     .       .      .     #       .           .\n";
	file << "        .      .         ###            .      .      .\n";
	file << "      .      .   \"#:. .:##\"##:. .:#\"  .      .\n";
	file << "          .      . \"####\"###\"####\"  .\n";
	file << "       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n";
	file << "  .             \"#########\"#########\"        .        .\n";
	file << "        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n";
	file << "     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n";
	file << "                .\"##\"#####\"#####\"##\"           .      .\n";
	file << "    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n";
	file << "      .     \"#######\"##\"#####\"##\"#######\"      .     .\n";
	file << "    .    .     \"#####\"\"#######\"\"#####\"    .      .\n";
	file << "            .     \"      000      \"    .     .\n";
	file << "       .         .   .    000     .        .       .\n";
	file << ".. .. ...................O000O........................ ......\n";
	file.close();

}