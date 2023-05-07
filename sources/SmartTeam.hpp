#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP 

#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Team.hpp"

namespace ariel 
{
    using namespace std;

    class SmartTeam : public Team
    {
    private:
        // no private members
    public:
        SmartTeam(Character *leader);
        ~SmartTeam();
        bool add(const Character *newTeamMember) override;
        void attack(Team *newTeamMember) override; // not const becuase changes objects
        int stillAlive();
        void print() override;

    };
    
}

#endif