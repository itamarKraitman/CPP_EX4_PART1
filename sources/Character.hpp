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

    public:
        Character(const std::string &name, Point location);
        virtual ~Character() = default;
        bool isAlive();
        double distance(const Character &other); // by reffernce to
        virtual string print() = 0;

        string getName();
        Point getLocation();
    };

}

#endif