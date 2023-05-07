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
    bool Team2::add(const Character *newTeamMember) {return true;}
    void Team2::attack(Team *newTeamMember) {}
    int Team2::stillAlive() {return 1;}
    string Team2::print() {return "1";}

} 
