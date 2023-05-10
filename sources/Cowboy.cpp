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
    string Cowboy::print() { return "1"; }

    int Cowboy::getHitPoints() { return this->hitPoints; }
    bool Cowboy::setHitPoints(int number)
    {
        this->hitPoints = number;
        return true;
    }
    int Cowboy::getAmoutOfBullets() { return this->amountOfBullets; }
    bool Cowboy::setAmountOfBullets(int number)
    {
        this->amountOfBullets = number;
        return true;
    }

}