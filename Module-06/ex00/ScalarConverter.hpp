#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &other);
	~ScalarConverter(void);
	ScalarConverter &operator=(ScalarConverter const &other);

public:
	static void convert(const std::string &str);

};

#endif
