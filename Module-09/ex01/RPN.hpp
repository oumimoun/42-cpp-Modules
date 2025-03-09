#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>

class RPN
{
public :
	RPN(void);
	RPN(RPN const &other);
	~RPN(void);
	RPN &operator = (RPN const &other);
	void processInput(const std::string &);
	double RPNCalculator(const std::string &input);
};

#endif