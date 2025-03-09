#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _numberValue(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int integer)
{
    std::cout << "Int constructor called" << std::endl;
    _numberValue = integer << _fractionalBits;
}

Fixed::Fixed( const float floatingPoint)
{
    std::cout << "Float constructor called" << std::endl;
    _numberValue = roundf( floatingPoint * (1 << _fractionalBits));
}

float Fixed::toFloat( void ) const
{
    return (float)(_numberValue) / (1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
    return _numberValue >> _fractionalBits;
}

Fixed::Fixed( const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        _numberValue = other._numberValue;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _numberValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _numberValue = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedPoint)
{
    out << fixedPoint.toFloat();
    return out;
}

