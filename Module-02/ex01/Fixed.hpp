#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _numberValue;
    static const int _fractionalBits;
public:
    Fixed();
    Fixed(const int integer);
    // floating-point constructor
    Fixed(const float floatingPoint);
    // A copy constructor
    Fixed(const Fixed& other);
    //  A copy assignment operator overload.
    Fixed& operator=(const Fixed& other);
    // destructor
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    int toInt( void ) const;
    float toFloat( void ) const;
    // static s
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif