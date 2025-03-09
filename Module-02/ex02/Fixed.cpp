#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _numberValue(0) {}

Fixed::Fixed( const int integer)
{
    _numberValue = integer << _fractionalBits;
}

Fixed::Fixed( const float floatingPoint) 
{
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
    *this = obj;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _numberValue = other._numberValue;
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
    return _numberValue;
}

void Fixed::setRawBits(int const raw) {
    _numberValue = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixedPoint)
{
    out << fixedPoint.toFloat();
    return out;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}


const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}



Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}


const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}


Fixed& Fixed::operator++() {
    _numberValue++;
    return *this;
}


Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    _numberValue++;
    return temp;
}


Fixed& Fixed::operator--() {
    _numberValue--;
    return *this;
}


Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    _numberValue--;
    return temp;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed result;
    result.setRawBits(this->_numberValue + other._numberValue);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const 
{
    Fixed result;
    result.setRawBits(this->_numberValue - other._numberValue);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;
    result.setRawBits((this->_numberValue * other._numberValue) / (1 << _fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other._numberValue == 0) {
        std::cerr << "Error: Division by zero!" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((_numberValue << _fractionalBits) / other._numberValue);
    return result;
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->_numberValue > other._numberValue);
}

bool Fixed::operator<(const Fixed& other) const
{
    return ( this->_numberValue < other._numberValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->_numberValue >= other._numberValue);
}

bool Fixed::operator<=(const Fixed& other) const 
{
    return (this->_numberValue <= other._numberValue);
}

bool Fixed::operator==(const Fixed& other) const 
{
    return (this->_numberValue == other._numberValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->_numberValue != other._numberValue);
}
