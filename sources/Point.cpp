#include <iostream>
#include "Point.hpp"

namespace ariel
{
    Point::Point() {}
    Point::Point(double x, double y) : x(x), y(y) {}
    double Point::distance(const Point &other) { return 1; }
    void Point::print() { cout << "(" << this->x << "," << this->y << ")"; }
    Point Point::moveTowards(Point origin, Point destination, double distance) { return Point(1, 1); }

    double Point::getX() { return this->x; }
    double Point::getY() { return this->y; }
}