#ifndef TEAM_HPP
#define TEAM_HPP 

#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel 
{
    using namespace std;

    class Team
    {
    protected:
        Character &leader;
        vector<Character> squad;
    public:
        Team(Character *leader);
        ~Team();
        virtual bool add(const Character *newTeamMember);
        virtual void attack(Team *newTeamMember); // not const becuase changes objects
        int stillAlive();
        virtual void print();

    };
    
}

#endif
