#include <iostream>
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(const std::string &name, Point location) : Character(name, location), name(name) {}
    Ninja::~Ninja() {}
    void Ninja::move(const Character *other) {return;}
    bool Ninja::slash(Character *other) {return true;}
    int Ninja::getSpeed() {return this->speed;}
    bool Ninja::setHitPoints(int amountOfHitPoints) {return true;}
    string Ninja::print() {return "1";}


}