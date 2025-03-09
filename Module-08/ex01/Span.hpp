#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <ctime>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _numbers;

public :
	Span(void);
	Span(unsigned int N);
	Span(Span const &other);
	~Span(void);
	Span &operator = (Span const &other);

	void	addNumber(int);

	int shortestSpan();
	int longestSpan();

	template< typename IT>
	void addNumbers(IT begin, IT end)
	{
		if (_numbers.size() + std::distance(begin, end) > _N)
        	throw std::overflow_error("Adding this range exceeds Span's capacity.");
		_numbers.insert(_numbers.end(), begin, end);
	}

};

#endif