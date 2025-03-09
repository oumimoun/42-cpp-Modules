#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return (*this);
}

static void toChar(double num)
{
	if (std::isnan(num) || std::isinf(num) || num < 0 || num > 127)
		std::cout << "char: impossible" << std::endl;
	else if (num < 32 || num == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
}

static void toInt(double num)
{
	if (std::isnan(num) || std::isinf(num) || num < INT_MIN || num > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
}

static void toFloat(double num)
{
	if (std::isnan(num))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(num))
		std::cout << "float: " << (num > 0 ? "+inff" : "-inff") << std::endl;
	else
	{
		std::cout << "float: " << static_cast<float>(num);
		if (num == static_cast<int>(num))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void toDouble(double num)
{
	if (std::isnan(num))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(num))
		std::cout << "double: " << (num > 0 ? "+inf" : "-inf") << std::endl;
	else
	{
		std::cout << "double: " << num;
		if (num == static_cast<int>(num))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverter::convert(const std::string& str)
{
	std::string value = (!str.empty() && str[str.size() - 1] == 'f') ? str.substr(0, str.size() - 1) : str;
	double num = atof(value.c_str());
	toChar(num);
	toInt(num);
	toFloat(num);
	toDouble(num);
}
