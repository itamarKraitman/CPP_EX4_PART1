#ifndef YOUNGNINJA_HPP
#define YOUNGNINGA_HPP

#include <iostream>
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    using namespace std;

    class YoungNinja : public Ninja
    {
    private:
        const std::string &name;
        Point location;

    public:
        YoungNinja(const std::string &name, Point location);
        ~YoungNinja();
        void move(const Character *other) override;
        bool slash(Character *other) override;
        int getSpeed() override;
        bool setHitPoints(int amountOfHitPoints) override;
        void print() override;
    };

}

#endif