#include <iostream>
#include "Character.hpp"
#include "TrainedNinja.hpp"
#include "Ninja.hpp"

namespace ariel
{
    TrainedNinja::TrainedNinja(const std::string &name, Point location) : Ninja(name, location), name(name), location(location)
    {
        this->hitPoints = 120;
        this->speed = 12;
    }  
    TrainedNinja::~TrainedNinja() {}
    void TrainedNinja::move(const Character *other) {return;}
    bool TrainedNinja::slash(Character *other) {return true;}
    int TrainedNinja::getSpeed() {return 1;}
    bool TrainedNinja::setHitPoints(int amountOfHitPoints) {return true;}
    void TrainedNinja::print() {return;}
}