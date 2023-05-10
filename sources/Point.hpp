#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

namespace ariel
{
    using namespace std;

    class Point
    {
    private:
        double x;
        double y;

    public:
        Point();
        Point(double x, double y);
        double distance(Point other);                                 // calculates the distance between two pints
        void print();                                                        // prints the point in the format of "(x,y)"
        Point moveTowards(Point origin, Point destination, double distance); // within the given distance, returns the closest point to the destination point

        double getX();
        double getY();

    };
}

#endif