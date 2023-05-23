#include "Character.hpp"
using namespace std;
using namespace ariel;

Character :: Character(string name, const Point &place , int lives): 
name (name), location (place) , lives( lives){}

Character::Character(const Character &other)
    : location(other.location), lives(other.lives),
      name(other.name), inGame(false) {}

Character::Character(Character &&other) noexcept
    : location(other.location), lives(other.lives),
      name(other.name),inGame(false) {}

Character &Character::operator=(const Character &other) {
  if (this == &other)
    return *this;

  name = other.name;
  location = other.location;
  lives = other.lives;
  inGame = other.inGame;


  return *this;
}

Character &Character::operator=(Character &&other) noexcept {
  if (this == &other)
    return *this;

  name = other.name;
  location = other.location;
  lives = other.lives;
  inGame = other.inGame;
  return *this;
}

bool Character::isAlive() const{
    if( this->lives<=0){
        return false;
    }
    return true;
}

double Character :: distance(Character *other){
    return this->getLocation().distance(other->getLocation());
}

void Character:: hit (int number){
    if (number <0){
        __throw_invalid_argument("must be a pos number");
    }
    this->lives -= number;
    if (this->lives<0){
        this->lives=0; 
    }
}

string Character:: getName(){
    return this->name;
}

int Character :: getLives(){
    return this->lives;
}

Point Character:: getLocation(){
    return this->location;
}

string Character:: print(){
    if ( this->lives == 0){
        return ("("+ this->getName()+")"+ "locaton:" + this->getLocation().print());
    }
    else {
        return ("name:"+this->getName() +"lives:"+ to_string(this->getLives())+ "locaton:" + this->getLocation().print());
    }
}

void Character::setLocation(Point newLocation){
    this->location = newLocation;
}

void Character:: setINGAME(){
    this->inGame = true;
}

bool Character :: getINGAME(){
    return this->inGame;
}

Character::~Character(){}
