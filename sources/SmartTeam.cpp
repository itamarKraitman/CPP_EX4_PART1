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
    bool SmartTeam::add(const Character *newTeamMember) {return true;}
    void SmartTeam::attack(Team *newTeamMember) {}
    int SmartTeam::stillAlive() {return 1;}
    string SmartTeam::print() {return "1";}

} 
