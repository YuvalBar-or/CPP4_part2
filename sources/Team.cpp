#include "Team.hpp"
#include "Character.hpp"
#include <vector>
#include <iostream>
#include <cfloat>
#include <stdexcept>
using namespace std; 
using namespace ariel;

Team:: Team (Character *leader): leader(leader){
    if (leader->getINGAME()){
        throw runtime_error("leader already in game");
    } 
    team.push_back(leader);
    leader->setINGAME();
}


Team::Team(Team &&other)noexcept{
    this->leader = other.leader;
    this->team = other.team;
}

Team::Team(const Team &other) : leader(other.leader) {}

void Team :: add ( Character *character) {
  if (character == nullptr)
    throw runtime_error("there is no enemy");
  if (!character->isAlive())
    throw runtime_error("the character is dead");
  if (team.size() == 10 || character->getINGAME()) {
    throw runtime_error("there are maximum 10 members that are not already in other teams");
  }
  this->team.push_back(character);
  character->setINGAME();
}
 
int Team :: stillAlive(){
  int result = 0;
  for (Character *member : team)
    if (member->isAlive())
      result++;
  return result;
}

void Team :: print(){
    for (Character *member : team){
        if (member != nullptr){
            cout << member->print() << endl;
        }
    }
}

Team::~Team(){}

Team:: Team(){
  return; 
}

Team &Team::operator=(const Team &other){
    this->leader = other.leader;
    this->team = other.team;
    return *this;
}

Team &Team::operator=( Team &&other) noexcept{
    this->leader = other.leader;
    this->team = other.team;
    return *this;
}

vector<Character *> *Team::getMembers() { return &team; }

Character *Team::closestMember(vector<Character *> &other, const Point &){
    double minDis = DBL_MAX;
    Character *result = NULL;
    for (Character *member : other)
      if (member->isAlive() && leader->distance(member) < minDis)
      {
        minDis = leader->distance(member);
        result = member;
      }
    return result;
  }

void Team::attack(Team *other){
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

void Team :: setLeader(Character *newLeader){
    this->leader = newLeader;
}



