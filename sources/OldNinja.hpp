#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include <iostream>
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    using namespace std;

    class OldNinja : public Ninja
    {

        int HITS_POINTS = 180;
         int SPEED = 8;

    private:
        
    public:
        OldNinja(const std::string &name, Point location);
        ~OldNinja();
        void move(const Character *other) override;
        bool slash(Character *other) override;
        string print() override;
    };

}

#endif