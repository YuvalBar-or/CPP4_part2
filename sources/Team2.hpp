#pragma once
#include "Team.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
#include <vector>
using namespace std; 
namespace ariel{};

class Team2: public Team{
    private:
        vector<Character *> team;
        Character *leader;
    
    public:
        Team2 (Character *leader);
        void print();
        Team2 (const Team2 & other);
        // Team2() = delete;
        Team2& operator=(const Team2 &other);
        Team2& operator=( Team2&& other) noexcept;
        Team2(Team2 &&other)noexcept;
        ~Team2();
        


};