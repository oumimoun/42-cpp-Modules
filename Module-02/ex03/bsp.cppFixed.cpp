#include "Point.hpp"
#include "Fixed.hpp"

float get_x_vector(Point const Q, Point const R)
{
    return ((R.getX().toFloat() - Q.getX().toFloat()));
}

float get_y_vector(Point const Q, Point const R)
{
    return ((R.getY().toFloat() - Q.getY().toFloat()));
}

bool isIn(float cross1, float cross2, float cross3)
{
    return ((cross1 > 0 && cross2 > 0 && cross3 > 0) || (cross1 < 0 && cross2 < 0 && cross3 < 0));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

    float ABx = get_x_vector(a , b);
    float ABy = get_y_vector(a , b);

    float APx = get_x_vector(a, point);
    float APy = get_y_vector(a, point);

    float BCx = get_x_vector(b , c);
    float BCy = get_y_vector(b , c);

    float BPx = get_x_vector(b , point);
    float BPy = get_y_vector(b , point);

    float CAx = get_x_vector(c , a);
    float CAy = get_y_vector(c, a);

    float CPx = get_x_vector(c , point);
    float CPy = get_y_vector(c , point);

    float cross1 = ABx * APy - ABy * APx;
    float cross2 = BCx * BPy - BCy * BPx;
    float cross3 = CAx * CPy - CAy * CPx;

    bool isInside = isIn(cross1, cross2, cross3);

    return isInside;
}
