#include <iostream>
#include <vector>
#include "Team.hpp"
#include "Team2.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader) {}
    Team2::~Team2() {}
    bool Team2::add(const Character *newTeamMember) {}
    void Team2::attack(Team *newTeamMember) {}
    int Team2::stillAlive() {}
    void Team2::print() {}

} 
