#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    using namespace std;

    class Ninja : public Character
    {
    protected:
        int speed;
        int hitPoints;

    public:
        Ninja(const std::string &name, Point location);
        ~Ninja();
        virtual void move(const Character *other);
        virtual bool slash(Character *other);
        string print() override;

        int getSpeed();
        bool setHitPoints(int amountOfHitPoints);
        bool setSpeed(int newSpeed);
        int getHitPoints();
    };

}

#endif