#include <iostream>
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(const std::string &name, Point location) : Character(name, location) {}
    Ninja::~Ninja() {}
    void Ninja::move(const Character *other) { return; }
    bool Ninja::slash(Character *other) { return true; }
    string Ninja::print() { return "1"; }

    int Ninja::getSpeed() { return this->speed; }
    bool Ninja::setSpeed(int newSpeed)
    {
        this->speed = newSpeed;
        return true;
    }
    int Ninja::getHitPoints(int amountOfHitPoints) { return this->hitPoints; }
    bool Ninja::setHitPoints(int amountOfHitPoints)
    {
        this->hitPoints = amountOfHitPoints;
        return true;
    }

}