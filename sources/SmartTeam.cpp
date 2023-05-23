#include "Team.hpp"
#include "SmartTeam.hpp"
#include "Character.hpp"
#include <vector>
#include <iostream>
using namespace std; 
using namespace ariel;

SmartTeam:: SmartTeam (Character *leader): Team(leader){}
SmartTeam::SmartTeam(const SmartTeam &other):Team(other){}

void SmartTeam :: print(){
    for (Character *member : team)
       if (member->isAlive())
            cout << member->print() << endl;
}

SmartTeam &SmartTeam::operator=(const SmartTeam &other){
    this->leader = other.leader;
    this->team = other.team;
    return *this;
}

SmartTeam &SmartTeam::operator=( SmartTeam &&other) noexcept{
    this->leader = other.leader;
    this->team = other.team;
    return *this;
}

SmartTeam::SmartTeam(SmartTeam &&other)noexcept{
    this->leader = other.leader;
    this->team = other.team;
}

SmartTeam::~SmartTeam(){}    
    



