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
        const std::string &name;
        Point location;
        int speed;
    public:
        Ninja(const std::string &name, Point location);
        ~Ninja();
        virtual void move(const Character *other);
        virtual bool slash(Character *other);
        virtual int getSpeed();
        virtual bool setHitPoints(int amountOfHitPoints);
        void print() override;
    };
    
}

#endif