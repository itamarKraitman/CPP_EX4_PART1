#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    using namespace std;

    class Cowboy : public Character
    {

         int NUM_BULLETS = 6;
         int HIT_POINTS = 110;

    private:
        int amountOfBullets = NUM_BULLETS;
        int hitPoints = HIT_POINTS;

    public:
        Cowboy(const std::string &name, Point location);
        ~Cowboy();
        bool shoot(Character *other); // returns true if hit
        bool hasBoolets();
        void reload();
        string print() override; // "override" only inside .hpp

        int getHitPoints();
        bool setHitPoints(int number);
        int getAmoutOfBullets();
        bool setAmountOfBullets(int number);

        // no need to define get methods for name and location since they defined inside character
    };

}

#endif