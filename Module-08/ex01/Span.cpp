#include "Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const &other)
{
	*this = other;
}

Span::~Span(void) {}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_N = other._N;
		_numbers = other._numbers;
	}
	return (*this);
}

void Span::addNumber(int num)
{
	if (_numbers.size() >= _N)
		throw std::overflow_error("Span is full, cannot add more numbers.");
	_numbers.push_back(num);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to calculate span.");
	std::sort(_numbers.begin(), _numbers.end());
	int result = std::numeric_limits<int>::max();
	for (size_t i = 1; i < _numbers.size(); i++)
	{
		result = std::min(result, _numbers[i] - _numbers[i - 1]);
	}
	return result;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough numbers to calculate span.");
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

