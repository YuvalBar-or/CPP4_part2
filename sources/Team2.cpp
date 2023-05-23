#include "Team.hpp"
#include "Team2.hpp"
#include "Character.hpp"
#include <vector>
#include <iostream>
using namespace std; 
using namespace ariel;

Team2:: Team2 (Character *leader): Team(leader){}
Team2:: Team2(const Team2 &other):Team(other){}


void Team2 :: print(){
    for (Character *member : this->team)
        cout << member->print() << endl;
}


Team2 &Team2::operator=(const Team2 &other){
    this->leader = other.leader;
    this->team = other.team;
    return *this;
}

Team2 &Team2::operator=( Team2 &&other) noexcept{
    this->leader = other.leader;
    this->team = other.team;
    return *this;
}

Team2::Team2(Team2 &&other)noexcept{
    this->leader = other.leader;
    this->team = other.team;
}

Team2::~Team2(){}




