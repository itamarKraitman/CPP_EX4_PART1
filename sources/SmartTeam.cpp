#include <iostream>
#include <vector>
#include "Team.hpp"
#include "SmartTeam.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}
    SmartTeam::~SmartTeam() {}
    bool SmartTeam::add(const Character *newTeamMember) {}
    void SmartTeam::attack(Team *newTeamMember) {}
    int SmartTeam::stillAlive() {}
    void SmartTeam::print() {}

} 
