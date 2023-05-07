#include <iostream>
#include <vector>
#include "Team.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    Team::Team(Character *leader) : leader(*leader) {}
    Team::~Team() {}
    bool Team::add(const Character *newTeamMember) {}
    void Team::attack(Team *newTeamMember) {}
    int Team::stillAlive() {}
    void Team::print() {}

} 
