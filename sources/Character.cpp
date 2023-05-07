#include <iostream>
#include "Character.hpp"

namespace ariel
{
    Character::Character(const std::string &name, Point location) : name(name), location(location) {}
    bool Character::isAlive() { return true; }
    double Character::distance(const Character &other) { return 1; } // by reffernce to
    void Character::print() { return; }

    string Character::getName() { return this->name; }
    Point Character::getLocation() { return this->location; }
    int Character::getHitPoints() { return this->hitPoints; }
}