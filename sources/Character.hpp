#pragma once
#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel
{
    class Character
    {
        Point location;
        int hitPoints;
        string name;

    public:
        Character();
        Character(string, Point, int);

        bool isAlive() const;
        double distance(Character *);
        string getName() const;
        Point getLocation() const;
        Point setLocation(Point other);
        int getHitPoints() const;
        void setHitPoints(int hit);
        virtual string print() = 0;

        virtual ~Character() = default;                   // destructor
        Character(const Character &) = delete;            // Copy constructor
        Character &operator=(const Character &) = delete; // Copy assignment operator
        Character(Character &&) = delete;                 // Move constructor
        Character &operator=(Character &&) = delete;      // Move assignment operator
    };

}