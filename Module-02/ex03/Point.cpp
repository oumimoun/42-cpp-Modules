#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() :_x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {
}

Point::~Point() {}

Point::Point( const Point &obj) : _x(obj._x) , _y(obj._y) {
}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}

Point &Point::operator=(Point const &other)
{
    if (this != &other)
    {
        (Fixed) this->_x = other.getX();
        (Fixed) this->_y = other.getY();
    }
    return *this;
}

