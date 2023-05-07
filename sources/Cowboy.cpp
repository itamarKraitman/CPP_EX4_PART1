#include <iostream>
#include "Character.hpp"
#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(const std::string &name, Point location) : Character(name, location)
    {
        this->hitPoints = 110;
    }
    Cowboy::~Cowboy() {}
    bool Cowboy::shoot(Character *other) { return true; }
    bool Cowboy::hasBoolets() { return true; }
    void Cowboy::reload() { return; }
    string Cowboy::print() {return "1";}

    bool Cowboy::setHitPoints(int number) { return true; }

}