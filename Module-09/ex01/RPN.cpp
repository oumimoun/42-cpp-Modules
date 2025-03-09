#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const &other)
{
	*this = other;
}

RPN::~RPN(void) {}

RPN &RPN::operator = (RPN const &other)
{
	(void)other;
	return (*this);
}

bool isOperation(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

double calculate(double n1, double n2, char operation)
{
	if (operation == '+')
		return n1 + n2;
	if (operation == '-')
		return n1 - n2;
	if (operation == '*')
		return n1 * n2;
	if (operation == '/')
    {
        if (n2 == 0)
        {
            std::cerr << "You can't operate division by zero" << std::endl;
            exit(1);
        }
		return n1 / n2;
    } 
	return -1;
}

double RPN::RPNCalculator(const std::string &input)
{
    std::stack<double> numbers;

    for (size_t i = 0; i < input.size(); i++)
    {
        char c = input[i];
        if (isspace(c))
            continue;

        if (isOperation(c))
        {
            if (numbers.size() < 2)
            {
                std::cerr << "Error: Not enough operands." << std::endl;
                exit(1);
            }

            double n2 = numbers.top();
            numbers.pop();
            double n1 = numbers.top();
            numbers.pop();

            double result = calculate(n1, n2, c);
            numbers.push(result);
        }
        else if (isdigit(c))
        {
            numbers.push(c - '0');
        }
    }

    if (numbers.size() != 1)
    {
        std::cerr << "Error: Invalid RPN expression." << std::endl;
        exit(1);
    }

    return numbers.top();
}

void RPN::processInput(const std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && !isspace(input[i]))
		{
			std::cerr << "Error" << std::endl;
			exit(1);
		}
	}
	std::cout << RPNCalculator(input) << std::endl;
}
