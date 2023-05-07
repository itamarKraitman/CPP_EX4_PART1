#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include "Character.hpp"

namespace ariel
{
    using namespace std;

    class Cowboy : public Character
    {
    private:
        int amountOfBullets = 6;

    public:
        Cowboy(const std::string &name, Point location);
        ~Cowboy();
        bool shoot(Character *other); // returns true if hit
        bool hasBoolets();
        void reload();
        string print() override; // "override" only inside .hpp

        bool setHitPoints(int number);

        // no need to define get methods for name and location since they defined inside character
    };

}

#endif