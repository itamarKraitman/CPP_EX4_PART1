#include <iostream>

namespace ariel 
{
    class Point
    {
    private:
        double x;
        double y;
    public:
        Point(double x, double y);
        double distance(const Point &other);
    };
}