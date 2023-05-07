#include <iostream>
#include "Character.hpp"
#include "YoungNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{
    YoungNinja::YoungNinja(const std::string &name, Point location) : Ninja(name, location)
    {
        this->hitPoints = 100;
        this->speed = 14;
    }  
    YoungNinja::~YoungNinja() {}
    void YoungNinja::move(const Character*other) {return;}
    bool YoungNinja::slash(Character *other) {return true;}
    int YoungNinja::getSpeed() {return 1;}
    bool YoungNinja::setHitPoints(int amountOfHitPoints) {return true;}
    string YoungNinja::print() {return "1";}
}