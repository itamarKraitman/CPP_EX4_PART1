#include <iostream>
#include "Character.hpp"
#include "TrainedNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{
    TrainedNinja::TrainedNinja(const std::string &name, Point location) : Ninja(name, location)
    {
        this->hitPoints = HITS_POINTS;
        this->speed = SPEED;
    }  
    TrainedNinja::~TrainedNinja() {}
    void TrainedNinja::move(const Character *other) {return;}
    bool TrainedNinja::slash(Character *other) {return true;}
    string TrainedNinja::print() {return "1";}
}