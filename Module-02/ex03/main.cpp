#include "Point.hpp"

int main() {
    Point a(1, 2);
    Point b(3, 5);
    Point c(8, 3);
    Point point(4, 4);

    if (bsp(a, b, c, point) == true)
        std::cout << "The Point is inside the triangle" << std::endl;
    else
        std::cout << "The Point is outside the triangle" << std::endl;

    return 0;
}
