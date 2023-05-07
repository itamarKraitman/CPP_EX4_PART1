#ifndef TEAM2_HPP
#define TEAM2_HPP 

#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Team.hpp"

namespace ariel 
{
    using namespace std;

    class Team2 : public Team
    {
    private:
        // no private members
    public:
        Team2(Character *leader);
        ~Team2();
        bool add(const Character *newTeamMember) override;
        void attack(Team *newTeamMember) override; // not const becuase changes objects
        int stillAlive();
        string print() override;

    };
    
}

#endif