#include <iostream>
#include <cmath>
#include "Point.hpp"

namespace ariel
{
    Point::Point() {}
    Point::Point(double x, double y) : x(x), y(y) {}
    double Point::distance(Point other) 
    { 
        return std::round(sqrt(pow(other.getX() - this->x, 2) + pow(other.getY() - this->y, 2) * 1.0) * 1000.0) / 1000.0; 
    }
    void Point::print() { cout << "(" << this->x << "," << this->y << ")"; }
    Point Point::moveTowards(Point origin, Point destination, double distance) { return Point(1, 1); }

    double Point::getX() { return this->x; }
    double Point::getY() { return this->y; }
}