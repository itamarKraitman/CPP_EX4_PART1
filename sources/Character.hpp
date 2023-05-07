#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "Point.hpp"

namespace ariel
{
    using namespace std;

    // abstract class to repesent Cowbys and Ninjas
    class Character
    {
    protected:
        const std::string &name;
        Point location;
        int hitPoints;

    public:
        Character(const std::string &name, Point location);
        bool isAlive();
        double distance(const Character &other); // by reffernce to
        virtual void print() = 0;

        string getName();
        Point getLocation();
        int getHitPoints();
    };

}

#endif