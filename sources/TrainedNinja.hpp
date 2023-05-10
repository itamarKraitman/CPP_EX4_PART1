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

        int HITS_POINTS = 120;
        int SPEED = 12;

    private:

    public:
        TrainedNinja(const std::string &name, Point location);
        ~TrainedNinja();
        void move(const Character *other) override;
        bool slash(Character *other) override;
        string print() override;
    };

}

#endif