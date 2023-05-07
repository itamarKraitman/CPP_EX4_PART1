#ifndef TRAINEDNINJA_HPP
#define TRAINEDNINJA_HPP

#include <iostream>
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    using namespace std;

    class TrainedNinja : public Ninja
    {
    private:
        const std::string &name;
        Point location;

    public:
        TrainedNinja(const std::string &name, Point location);
        ~TrainedNinja();
        void move(const Character *other) override;
        bool slash(Character *other) override;
        int getSpeed() override;
        bool setHitPoints(int amountOfHitPoints) override;
        void print() override;
    };

}

#endif