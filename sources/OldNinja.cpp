#include <iostream>
#include "Character.hpp"
#include "OldNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{
    OldNinja::OldNinja(const std::string &name, Point location) : Ninja(name, location)
    {
        this->hitPoints = 180;
        this->speed = 8;
    }  
    OldNinja::~OldNinja() {}
    void OldNinja::move(const Character *other) {return;}
    bool OldNinja::slash(Character *other) {return true;}
    int OldNinja::getSpeed() {return 1;}
    bool OldNinja::setHitPoints(int amountOfHitPoints) {return true;}
    string OldNinja::print() {return "1";}
}