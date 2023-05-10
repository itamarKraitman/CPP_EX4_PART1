#include <iostream>
#include "Character.hpp"
#include "YoungNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{
    YoungNinja::YoungNinja(const std::string &name, Point location) : Ninja(name, location)
    {
        this->hitPoints = HITS_POINTS;
        this->speed = SPEED;
    }  
    YoungNinja::~YoungNinja() {}
    void YoungNinja::move(const Character*other) {return;}
    bool YoungNinja::slash(Character *other) {return true;}
    string YoungNinja::print() {return "1";}
}