#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include <iostream>
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    using namespace std;

    class YoungNinja : public Ninja
    {
    private:

    public:
        YoungNinja(const std::string &name, Point location);
        ~YoungNinja();
        void move(const Character *other) override;
        bool slash(Character *other) override;
        int getSpeed() override;
        bool setHitPoints(int amountOfHitPoints) override;
        string print() override;
    };

}

#endif