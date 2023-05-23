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

void SmartTeam::attack(SmartTeam *other){
     if (!other)
      throw invalid_argument("enemy is nullptr");

    if (stillAlive() == 0 || other->stillAlive() == 0)
      throw runtime_error("one of the team dead");

    if (!leader->isAlive())
      leader = closestMember(this->team, leader->getLocation());

    Character *target = nullptr;

    if (other->stillAlive() > 0)
      target = closestMember(other->team, leader->getLocation());
    else
      return;

    for (auto member : team){
      if (member != nullptr && member->isAlive()){
        if (target != nullptr && target->isAlive()){
          member->action(target);
        }
        else{
          target = closestMember(other->team, leader->getLocation());
          if (target != nullptr && target->isAlive()){
            member->action(target);
          }
        }
      }
    }
}

    



