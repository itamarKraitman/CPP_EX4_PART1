#include <iostream>
#include "Character.hpp"
#include "OldNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{
    OldNinja::OldNinja(const std::string &name, Point location) : Ninja(name, location)
    {
        this->hitPoints = HITS_POINTS;
        this->speed = SPEED;
    }  
    OldNinja::~OldNinja() {}
    void OldNinja::move(const Character *other) {return;}
    bool OldNinja::slash(Character *other) {return true;}
    string OldNinja::print() {return "1";}

    
}