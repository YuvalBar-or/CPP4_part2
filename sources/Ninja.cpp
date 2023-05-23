#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <string>
#include <iostream>

Ninja :: Ninja (string name ,const Point &location, int lives, int speed): 
Character(name , location , lives), speed (speed){}

void Ninja::move(Character *enemy){
    if (!this->isAlive()){
        return;
    }
    Point source = this->getLocation();
    Point dest = enemy->getLocation();
    Point newPoint = Point::moveTowards(source, dest, this->getspeed());
    this->setLocation(newPoint);

}

void Ninja::slash(Character *enemy) {
  if (!isAlive())
    throw runtime_error("Ninja is not alive");
  if (!enemy->isAlive())
    throw runtime_error("Enemy is not alive");
  if (this == enemy)
    throw runtime_error("Cannot attack itself");
  if (isAlive() && getLocation().distance(enemy->getLocation()) < 1)
    enemy->hit(40);
}

void Ninja::action(Character *enemy) {
  if (!isAlive() || !enemy->isAlive())
    return;
  if (distance(enemy) < 1)
    slash(enemy);
  else
    move(enemy);
}

int Ninja :: getspeed(){
    return this->speed; 
}


